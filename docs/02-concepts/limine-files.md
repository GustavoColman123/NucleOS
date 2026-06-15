# Limine Files

This note documents the Limine files used by NucleOS.

## Purpose

Limine provides bootloader files that allow NucleOS to be loaded from a bootable ISO.

## Important Files

### limine-bios.sys

Used by Limine for BIOS boot support.

### limine-bios-cd.bin

Used for BIOS CD-ROM boot support.

### limine-uefi-cd.bin

Used for UEFI CD-ROM boot support.

### BOOTX64.EFI

UEFI bootloader file for 64-bit x86 systems.

### BOOTIA32.EFI

UEFI bootloader file for 32-bit x86 systems.

## NucleOS Usage

NucleOS will use Limine files to create a bootable ISO.

The kernel path is defined in:

boot/limine.conf

The planned kernel path is:

boot:///boot/kernel.elf

## Safety Rule

These files are used only inside the NucleOS project and QEMU workflow.

They are not installed to the real laptop.
