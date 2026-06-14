# Bootable ISO

A bootable ISO is an image file that can be used to start a machine or virtual machine.

For NucleOS, the ISO will be used by QEMU.

## Role in NucleOS

The ISO will contain:

- Limine bootloader files
- Limine configuration
- NucleOS kernel ELF file

## Planned Flow

QEMU starts.

QEMU loads the ISO.

Limine starts.

Limine reads limine.conf.

Limine loads boot/kernel.elf.

NucleOS starts.

## ISO Root

The ISO root is the directory that becomes the root of the ISO image.

For NucleOS, the planned root directory is:

iso_root/

## Initial Layout

iso_root/
├── boot/
│   └── kernel.elf
└── limine.conf

## Important Rule

The ISO is not installed on the real laptop.

It is only used inside QEMU during development.
