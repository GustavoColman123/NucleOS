CC := gcc
LD := ld

CFLAGS := -ffreestanding -fno-stack-protector -fno-pic -m64 -Wall -Wextra -O2
LDFLAGS := -nostdlib -T linker.ld

BUILD_DIR := build
ISO_ROOT := iso_root

KERNEL_SOURCES := \
	src/kernel/kernel.c \
	src/arch/x86_64/boot_entry.c

KERNEL_OBJECTS := \
	$(BUILD_DIR)/kernel.o \
	$(BUILD_DIR)/boot_entry.o

KERNEL_ELF := $(BUILD_DIR)/kernel.elf

.PHONY: all clean iso-root

all: $(KERNEL_ELF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/kernel.o: src/kernel/kernel.c src/kernel/kernel.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/kernel/kernel.c -o $(BUILD_DIR)/kernel.o

$(BUILD_DIR)/boot_entry.o: src/arch/x86_64/boot_entry.c src/kernel/kernel.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/arch/x86_64/boot_entry.c -o $(BUILD_DIR)/boot_entry.o

$(KERNEL_ELF): $(KERNEL_OBJECTS) linker.ld
	$(LD) $(LDFLAGS) $(KERNEL_OBJECTS) -o $(KERNEL_ELF)

iso-root: $(KERNEL_ELF)
	mkdir -p $(ISO_ROOT)/boot
	cp $(KERNEL_ELF) $(ISO_ROOT)/boot/kernel.elf
	cp boot/limine.conf $(ISO_ROOT)/limine.conf

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ISO_ROOT)/boot/kernel.elf
	rm -f $(ISO_ROOT)/limine.conf
