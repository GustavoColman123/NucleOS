# NucleOS — Day 6: Inspecting the Kernel ELF

## Date

June 14, 2026

## Goal

Inspect the first generated NucleOS kernel ELF file.

The goal of this session is to understand what was produced by the build system created in Day 5.

## Main Idea

Day 5 created the first linker script and Makefile.

The build system produces:

build/kernel.elf

Day 6 focuses on inspecting that file.

A kernel ELF file is not just a random binary.

It contains structure, sections, symbols, and an entry point.

## Tools Used

- file
- readelf
- nm
- objdump

## What Each Tool Shows

### file

Shows general information about the binary.

It can identify whether the file is an ELF file and whether it targets x86_64.

### readelf -h

Shows the ELF header.

This includes information such as:

- architecture
- entry point
- file type
- program header information
- section header information

### readelf -S

Shows the sections inside the ELF file.

Important sections include:

- .text
- .rodata
- .data
- .bss

### nm

Shows symbols inside the binary.

For NucleOS, important symbols include:

- _start
- kernel_main

### objdump -d

Shows disassembled machine code.

This helps inspect what the compiler and linker produced.

## Important Concepts

### Entry Point

The entry point is the address where execution begins.

For NucleOS, the expected entry symbol is:

_start

### Sections

The linker script organizes the kernel into sections.

The most important initial sections are:

.text

Executable code.

.rodata

Read-only data.

.data

Initialized data.

.bss

Uninitialized data.

## Today's Result

Today I inspected the first generated NucleOS kernel ELF file.

I generated build reports using file, readelf, nm, and objdump.

These reports were saved inside:

docs/06-build-reports/

## Reflection

This session helped connect the linker script to the actual generated kernel file.

NucleOS is not bootable yet, but now I can inspect the binary that will eventually be loaded by Limine.
