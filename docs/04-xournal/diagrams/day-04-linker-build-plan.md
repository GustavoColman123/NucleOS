# Day 4 Xournal++ Diagram Plan

## Title

NucleOS — Day 4: Linker Script and Build Plan

## Main Diagram

kernel.c
boot_entry.c
↓
Compiler
↓
kernel.o
boot_entry.o
↓
Linker + linker.ld
↓
kernel.elf
↓
Limine
↓
QEMU
↓
NucleOS boots

## Notes

This diagram should explain how source code becomes a kernel file.

The goal is to understand the build pipeline before writing the first Makefile.
