# Limine ISO Structure

## Objective

Define the first ISO structure for NucleOS.

This structure prepares the project for a future bootable ISO.

## Planned Root Directory

iso_root/

## Planned Layout

iso_root/
├── boot/
│   └── kernel.elf
└── limine.conf

## Kernel Placement

The built kernel ELF file is generated at:

build/kernel.elf

For the ISO structure, it will be copied to:

iso_root/boot/kernel.elf

## Limine Configuration

The Limine configuration file is:

boot/limine.conf

During ISO preparation, it will be copied to:

iso_root/limine.conf

## Planned Limine Kernel Path

boot:///boot/kernel.elf

## Planned Build Flow

make
↓
build/kernel.elf
↓
prepare iso_root/
↓
copy kernel.elf
↓
copy limine.conf
↓
create ISO
↓
run QEMU

## Current Status

NucleOS can build kernel.elf.

NucleOS now has a planned ISO root structure.

NucleOS is not bootable yet.

## Next Step

Add Limine bootloader files and generate the first bootable ISO.
