# Minimal Kernel Structure

## Objective

Define the first minimal source structure for the NucleOS kernel.

This structure is not bootable yet.

It prepares the project for the first bootable kernel.

## Source Layout

src/kernel/

This directory contains generic kernel code.

src/arch/x86_64/

This directory contains architecture-specific code for x86_64.

## Current Files

src/kernel/kernel.c

Contains the generic `kernel_main` function.

src/kernel/kernel.h

Declares the kernel main function.

src/arch/x86_64/boot_entry.c

Contains the architecture-specific `_start` entry point.

src/arch/x86_64/README.md

Explains the purpose of the x86_64 architecture layer.

## Planned Execution Flow

Limine Bootloader
↓
_start
↓
kernel_main
↓
NucleOS kernel logic

## Why Separate Generic and Architecture Code?

The kernel should be organized clearly.

Generic kernel code should contain operating system logic.

Architecture-specific code should contain CPU-specific details.

This separation makes the project easier to understand and expand.

## Current Limitation

This structure does not boot yet.

The next technical steps will require:

- linker script
- build system
- Limine configuration
- bootable ISO
- QEMU run command
