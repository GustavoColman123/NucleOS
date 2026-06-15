# NucleOS — Day 8: Downloading and Integrating Limine

## Date

June 14, 2026

## Goal

Download and integrate Limine into the NucleOS project.

The goal of this session is not to boot yet.

The goal is to prepare the Limine bootloader files that will later be used to create a bootable ISO.

## Main Idea

NucleOS already has:

- a minimal kernel source structure
- a linker script
- a Makefile
- a generated kernel ELF file
- a Limine configuration file
- an ISO root structure

Now NucleOS needs the actual Limine bootloader files.

## Why Limine Is Needed

The kernel cannot start by itself.

A bootloader is responsible for loading the kernel into memory and transferring control to it.

For NucleOS, Limine will load:

boot:///boot/kernel.elf

## Safety Rule

NucleOS will not be installed on the real laptop.

Limine will only be used inside the project directory and later inside a QEMU ISO image.

No real boot partitions will be modified.

No real disk will be overwritten.

## Today's Result

Today I prepared the project to include Limine bootloader files.

This brings NucleOS closer to creating its first bootable ISO.

## Reflection

Day 7 prepared the ISO root structure.

Day 8 begins integrating the real bootloader files needed for the future ISO.
