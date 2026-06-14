# NucleOS — Day 4: Linker Script and Build Plan

## Date

June 14, 2026

## Goal

Understand what a linker script is and define the first build plan for NucleOS.

The goal of this session is not to boot yet.

The goal is to understand how source code becomes a kernel binary.

## Main Idea

A kernel is not built like a normal user program.

A normal program runs inside an operating system.

A kernel runs before there is an operating system.

Because of that, the kernel needs a controlled build process.

The compiler creates object files.

The linker combines those object files.

The linker script controls how the final kernel binary is arranged in memory.

## Build Flow

C source files
↓
Object files
↓
Linker script
↓
kernel.elf
↓
Bootable ISO
↓
QEMU

## Why a Linker Script?

A linker script tells the linker how to organize the final binary.

For a kernel, this matters because the bootloader expects the kernel to have a predictable structure.

The linker script can define:

- entry point
- code section
- read-only data section
- data section
- uninitialized memory section

## Planned Files

NucleOS will eventually need:

- linker.ld
- Makefile
- limine.conf
- kernel source files
- build directory
- ISO directory
- QEMU run command

## First Build Goal

The first build goal is:

Compile the minimal kernel source files into object files.

Then link them into a kernel ELF file.

Later, Limine will load that kernel ELF file.

## Today's Result

Today I documented the first build plan for NucleOS.

I now understand that the compiler and linker have different jobs.

The compiler translates source code.

The linker combines compiled objects and arranges the final kernel binary.

## Reflection

This session connects the source structure from Day 3 to the future first boot.

Before NucleOS can run in QEMU, it needs a clean build process.

The next step will be creating the first linker script and Makefile.
