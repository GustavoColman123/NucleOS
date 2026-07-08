CC := gcc
LD := ld
XORRISO := xorriso
LIMINE := ./tools/limine/limine
QEMU := qemu-system-x86_64

CFLAGS := -ffreestanding -fno-stack-protector -fno-pic -m64 -mcmodel=kernel -mno-red-zone -Wall -Wextra -O2 -Isrc
LDFLAGS := -nostdlib -T linker.ld -z max-page-size=0x1000

BUILD_DIR := build
ISO_ROOT := iso_root
ISO := $(BUILD_DIR)/nucleos.iso

KERNEL_OBJECTS := \
	$(BUILD_DIR)/kernel.o \
	$(BUILD_DIR)/terminal.o \
	$(BUILD_DIR)/boot_entry.o

KERNEL_ELF := $(BUILD_DIR)/kernel.elf

.PHONY: all clean iso-root iso run

all: $(KERNEL_ELF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/kernel.o: src/kernel/kernel.c src/kernel/kernel.h src/kernel/terminal.h src/limine.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/kernel/kernel.c -o $(BUILD_DIR)/kernel.o

$(BUILD_DIR)/terminal.o: src/kernel/terminal.c src/kernel/terminal.h src/limine.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/kernel/terminal.c -o $(BUILD_DIR)/terminal.o

$(BUILD_DIR)/boot_entry.o: src/arch/x86_64/boot_entry.c src/kernel/kernel.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/arch/x86_64/boot_entry.c -o $(BUILD_DIR)/boot_entry.o

$(KERNEL_ELF): $(KERNEL_OBJECTS) linker.ld
	$(LD) $(LDFLAGS) $(KERNEL_OBJECTS) -o $(KERNEL_ELF)

iso-root: $(KERNEL_ELF)
	mkdir -p $(ISO_ROOT)/boot/limine
	mkdir -p $(ISO_ROOT)/EFI/BOOT
	cp $(KERNEL_ELF) $(ISO_ROOT)/boot/kernel.elf
	cp boot/limine.conf $(ISO_ROOT)/limine.conf
	cp tools/limine/limine-bios.sys $(ISO_ROOT)/boot/limine/
	cp tools/limine/limine-bios-cd.bin $(ISO_ROOT)/boot/limine/
	cp tools/limine/limine-uefi-cd.bin $(ISO_ROOT)/boot/limine/
	cp tools/limine/BOOTX64.EFI $(ISO_ROOT)/EFI/BOOT/
	cp tools/limine/BOOTIA32.EFI $(ISO_ROOT)/EFI/BOOT/

iso: iso-root
	$(XORRISO) -as mkisofs \
		-b boot/limine/limine-bios-cd.bin \
		-no-emul-boot \
		-boot-load-size 4 \
		-boot-info-table \
		--efi-boot boot/limine/limine-uefi-cd.bin \
		-efi-boot-part \
		--efi-boot-image \
		--protective-msdos-label \
		$(ISO_ROOT) \
		-o $(ISO)
	$(LIMINE) bios-install $(ISO)

run: iso
	$(QEMU) -cdrom $(ISO) \
		-debugcon file:$(BUILD_DIR)/e9.log \
		-global isa-debugcon.iobase=0xe9

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ISO_ROOT)/boot/kernel.elf
	rm -f $(ISO_ROOT)/limine.conf
	rm -rf $(ISO_ROOT)/boot/limine
	rm -rf $(ISO_ROOT)/EFI
