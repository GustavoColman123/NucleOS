# First Bootable ISO

## Objective

Define how NucleOS creates its first bootable ISO image.

## Main Output

build/nucleos.iso

## Required Inputs

### Kernel

build/kernel.elf

### Limine Configuration

boot/limine.conf

### Limine Bootloader Files

tools/limine/limine-bios.sys

tools/limine/limine-bios-cd.bin

tools/limine/limine-uefi-cd.bin

tools/limine/BOOTX64.EFI

tools/limine/BOOTIA32.EFI

## ISO Root Layout

iso_root/
├── boot/
│   ├── kernel.elf
│   └── limine/
│       ├── limine-bios.sys
│       ├── limine-bios-cd.bin
│       └── limine-uefi-cd.bin
├── EFI/
│   └── BOOT/
│       ├── BOOTX64.EFI
│       └── BOOTIA32.EFI
└── limine.conf

## Build Flow

make iso

This should:

1. Build kernel.elf.
2. Prepare iso_root.
3. Copy the kernel.
4. Copy Limine configuration.
5. Copy Limine bootloader files.
6. Generate build/nucleos.iso using xorriso.
7. Apply Limine BIOS install step to the ISO.

## Current Status

NucleOS can build kernel.elf.

Day 9 adds the first ISO generation workflow.

## Next Step

Run the ISO in QEMU.
