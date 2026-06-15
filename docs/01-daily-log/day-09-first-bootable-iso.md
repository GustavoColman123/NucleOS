# NucleOS — Day 9: Creating the First Bootable ISO

## Date

June 14, 2026

## Goal

Create the first bootable ISO image for NucleOS.

The goal of this session is to connect the kernel ELF file, Limine bootloader files, the ISO root structure, and xorriso.

## Main Idea

NucleOS now has:

- a minimal kernel
- a linker script
- a Makefile
- a generated kernel ELF file
- Limine bootloader files
- an ISO root structure

Day 9 connects these pieces into a first ISO image.

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
copy Limine boot files
↓
xorriso
↓
build/nucleos.iso

## Why This Matters

An operating system kernel cannot be tested like a normal program.

It needs to be loaded by a bootloader.

The bootable ISO will allow QEMU to start Limine, and then Limine will load the NucleOS kernel.

## Important Files

- build/kernel.elf
- boot/limine.conf
- tools/limine/limine-bios.sys
- tools/limine/limine-bios-cd.bin
- tools/limine/limine-uefi-cd.bin
- tools/limine/BOOTX64.EFI
- tools/limine/BOOTIA32.EFI
- build/nucleos.iso

## Today's Result

Today I prepared the project to generate the first bootable ISO image.

## Reflection

NucleOS is now very close to the first real boot attempt in QEMU.

The next milestone will be running the ISO and seeing whether Limine can load the kernel.

## ISO Build Test

The ISO build command was executed with:

make iso

Result:

build/nucleos.iso was created successfully.

Limine BIOS stages were installed successfully.

This means NucleOS now has its first bootable ISO candidate.

The ISO has not been tested in QEMU yet.
