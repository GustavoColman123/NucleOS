# xorriso

xorriso is a tool used to create ISO images.

For NucleOS, xorriso is used to turn the iso_root directory into a bootable ISO file.

## Role in NucleOS

NucleOS uses xorriso to create:

build/nucleos.iso

This ISO image will later be booted inside QEMU.

## Why ISO Images Matter

An ISO image can contain the kernel, Limine files, and bootloader configuration.

QEMU can boot from the ISO.

## Planned Flow

iso_root/
↓
xorriso
↓
build/nucleos.iso
↓
QEMU

## Safety Rule

The ISO is only used inside QEMU during development.

It is not written to the real laptop disk.
