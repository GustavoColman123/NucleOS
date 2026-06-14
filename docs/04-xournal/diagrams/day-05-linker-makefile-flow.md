# Day 5 Xournal++ Diagram Plan

## Title

NucleOS — Day 5: First Linker Script and Makefile

## Diagram to Draw

kernel.c
↓
gcc
↓
kernel.o

boot_entry.c
↓
gcc
↓
boot_entry.o

kernel.o + boot_entry.o
↓
ld + linker.ld
↓
kernel.elf

## Side Notes

Make automates the build process.

The linker script controls the kernel layout.

kernel.elf will later be loaded by Limine.

## Goal

Show how NucleOS source files become the first kernel ELF file.
