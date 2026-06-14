# NucleOS — Day 7: Limine Files and First ISO Structure

## Date

June 14, 2026

## Goal

Prepare the first ISO directory structure for NucleOS using Limine.

The goal of this session is not to boot yet.

The goal is to understand how the kernel ELF file will be placed into a bootable ISO structure.

## Main Idea

Day 5 created the first build system.

Day 6 inspected the generated kernel ELF file.

Day 7 prepares the next step:

kernel.elf
↓
ISO root directory
↓
Limine configuration
↓
Bootable ISO
↓
QEMU

## Why ISO Structure Matters

QEMU can boot from an ISO image.

Limine needs configuration files inside the ISO.

The kernel ELF file must be placed in a predictable location.

The bootloader configuration must tell Limine which kernel file to load.

## Planned ISO Layout

iso_root/
├── boot/
│   └── kernel.elf
└── limine.conf

## Limine Configuration

The Limine configuration file will define a boot entry for NucleOS.

It will tell Limine where the kernel is located.

Initial planned kernel path:

boot:///boot/kernel.elf

## Today's Result

Today I prepared the first ISO directory structure for NucleOS.

I created a Limine configuration file and documented how kernel.elf will be placed inside the ISO root.

## Reflection

NucleOS is getting closer to the first boot.

The project now has a kernel ELF file and a planned ISO structure.

The next step will be connecting Limine boot files and generating the first bootable ISO.
