# Kernel ELF Inspection

## Objective

Document how to inspect the first NucleOS kernel ELF file.

## Build Output

The current build system produces:

build/kernel.elf

## Inspection Commands

### General File Information

file build/kernel.elf

### ELF Header

readelf -h build/kernel.elf

### ELF Sections

readelf -S build/kernel.elf

### Symbols

nm build/kernel.elf

### Disassembly

objdump -d build/kernel.elf

## Expected Symbols

The minimal kernel should contain:

_start

kernel_main

## Important Sections

The minimal kernel should contain sections such as:

.text

.rodata

.data

.bss

## Reports

The generated reports are stored in:

docs/06-build-reports/

## Why This Matters

Before booting NucleOS, it is important to understand what the build system is producing.

The kernel ELF file is the future input for Limine.
