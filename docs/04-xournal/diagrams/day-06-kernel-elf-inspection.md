# Day 6 Xournal++ Diagram Plan

## Title

NucleOS — Day 6: Inspecting the Kernel ELF

## Diagram to Draw

kernel.c + boot_entry.c
↓
Makefile
↓
kernel.elf
↓
file / readelf / nm / objdump
↓
ELF Header
Sections
Symbols
Disassembly

## Important Symbols

_start

kernel_main

## Important Sections

.text

.rodata

.data

.bss

## Goal

Show that kernel.elf is a structured binary, not just a random file.
