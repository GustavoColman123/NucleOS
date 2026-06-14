# Linker Script and Build Plan

## Objective

Define how the first NucleOS kernel will be built.

This plan connects source code, object files, the linker script, and the final kernel ELF file.

## Planned Build Pipeline

src/kernel/kernel.c
↓
build/kernel.o

src/arch/x86_64/boot_entry.c
↓
build/boot_entry.o

build/kernel.o + build/boot_entry.o
↓
linker.ld
↓
build/kernel.elf

build/kernel.elf
↓
Limine
↓
QEMU

## Important Files

### linker.ld

Controls the memory layout of the kernel.

### Makefile

Automates compilation, linking, ISO creation, and QEMU execution.

### kernel.elf

The final kernel file that Limine will load.

### limine.conf

Configuration file that tells Limine what kernel to load.

## Planned Sections

A kernel binary usually contains sections such as:

.text

Executable code.

.rodata

Read-only data.

.data

Initialized global data.

.bss

Uninitialized global data.

## Current Status

NucleOS has source files from Day 3.

NucleOS does not have a linker script yet.

NucleOS does not have a Makefile yet.

## Next Step

Create the first linker script and first Makefile.

Then test whether the minimal kernel can be compiled and linked.
