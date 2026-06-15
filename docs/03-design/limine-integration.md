# Limine Integration

## Objective

Document how Limine bootloader files are integrated into NucleOS.

## Current Limine Location

tools/limine/

## Download Location

tools/downloads/

The download directory is ignored by Git.

## Files Added

tools/limine/BOOTX64.EFI

UEFI bootloader file for 64-bit x86 systems.

tools/limine/BOOTIA32.EFI

UEFI bootloader file for 32-bit x86 systems.

tools/limine/limine-bios.sys

BIOS support file.

tools/limine/limine-bios-cd.bin

BIOS CD-ROM boot file.

tools/limine/limine-uefi-cd.bin

UEFI CD-ROM boot file.

## Planned ISO Usage

The future ISO creation process will use these files to make the NucleOS ISO bootable.

The current ISO root contains:

iso_root/
├── boot/
│   └── kernel.elf
└── limine.conf

## Planned Flow

Download Limine binary release
↓
Extract release archive
↓
Copy required bootloader files to tools/limine/
↓
Use files during ISO generation
↓
Boot ISO in QEMU

## Current Status

Limine bootloader files have been added to the project.

NucleOS is still not bootable yet.

## Next Step

Update the Makefile to generate a real bootable ISO using xorriso and Limine files.
