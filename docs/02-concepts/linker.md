# Linker

The linker is a tool that combines compiled object files into a final binary.

In NucleOS, the linker will create the kernel ELF file.

## Compiler vs Linker

The compiler translates source code into object files.

The linker combines object files into one final output.

Example:

kernel.c
↓
kernel.o

boot_entry.c
↓
boot_entry.o

kernel.o + boot_entry.o
↓
kernel.elf

## Why the Linker Matters for a Kernel

A kernel is not a normal application.

It must be loaded by a bootloader and placed correctly in memory.

The linker helps define the final layout of the kernel binary.

## Linker Script

A linker script controls how the linker arranges the final binary.

It can define:

- where execution starts
- where code is placed
- where data is placed
- where uninitialized memory is placed

## Entry Point

The entry point is the first symbol where execution begins.

For NucleOS, the planned early entry point is:

_start

Then _start calls:

kernel_main

## Planned Output

The first linked kernel output will likely be:

kernel.elf

This file will later be loaded by Limine.
