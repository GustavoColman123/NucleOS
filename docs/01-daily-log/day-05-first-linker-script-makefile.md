# NucleOS — Day 5: First Linker Script and Makefile

## Date

June 14, 2026

## Goal

Create the first linker script and Makefile for NucleOS.

The goal of this session is to make the project able to build a kernel ELF file.

## Main Idea

NucleOS needs a build system before it can boot.

The source files must be compiled into object files.

Then the object files must be linked into a final kernel ELF file.

The linker script controls the layout of the kernel binary.

## Build Flow

kernel.c
↓
kernel.o

boot_entry.c
↓
boot_entry.o

kernel.o + boot_entry.o
↓
linker.ld
↓
kernel.elf

## Files Created Today

- linker.ld
- Makefile
- docs/03-design/build-system-design.md
- docs/04-xournal/diagrams/day-05-linker-makefile-flow.md

## Why This Matters

A kernel cannot be built like a normal user-space program.

A normal program expects an operating system to load it.

A kernel is loaded by a bootloader.

Because of that, NucleOS needs a predictable binary layout and entry point.

## First Build Target

The first build target is:

build/kernel.elf

This file is not bootable by itself yet.

It is the kernel binary that will later be loaded by Limine.

## Today's Result

Today I created the first linker script and Makefile for NucleOS.

The project now has the foundation required to compile and link the minimal kernel.

## Reflection

This session connects the source structure from Day 3 and the build plan from Day 4.

NucleOS is now moving closer to the first bootable version.

## Build Test

The first build test was executed using:

make

Result:

build/kernel.elf was generated successfully.

This confirms that the minimal kernel source files can be compiled and linked.
