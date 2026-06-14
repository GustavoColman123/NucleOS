# ELF

ELF stands for Executable and Linkable Format.

It is a common binary format used on Unix-like systems.

For NucleOS, the first kernel output is:

build/kernel.elf

## Why ELF Matters

The kernel needs to be stored in a structured binary format.

A bootloader such as Limine can load an ELF kernel and transfer control to its entry point.

## ELF Header

The ELF header contains metadata about the binary.

It can include:

- architecture
- entry point
- program header offset
- section header offset
- file type

## Sections

ELF files contain sections.

Important kernel sections include:

### .text

Executable code.

### .rodata

Read-only data.

### .data

Initialized global data.

### .bss

Uninitialized global data.

## Symbols

Symbols are named locations inside the binary.

Examples in NucleOS:

_start

kernel_main

## Inspection Tools

Useful tools for inspecting ELF files:

file

readelf

nm

objdump

## NucleOS Usage

NucleOS currently builds a kernel ELF file.

This file is not a complete operating system image yet.

Later, Limine will load the kernel ELF file during the boot process.
