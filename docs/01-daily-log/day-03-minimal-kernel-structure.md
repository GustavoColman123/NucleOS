# NucleOS — Day 3: Minimal Kernel Structure

## Date

June 14, 2026

## Goal

Create the first minimal source structure for the NucleOS kernel.

The goal of this session is not to boot yet.

The goal is to prepare the basic kernel files and organize the source tree.

## Main Idea

Before NucleOS can boot, the project needs a clear kernel structure.

The kernel should be separated from architecture-specific code.

Generic kernel code should live in:

src/kernel/

Architecture-specific code should live in:

src/arch/x86_64/

## Why Structure Matters

A kernel project can become confusing very quickly.

Good structure helps separate responsibilities.

The generic kernel should not depend too much on one specific CPU architecture.

Architecture-specific code should handle low-level details such as entry points, CPU instructions, and hardware-specific initialization.

## Files Created Today

Today I created:

- src/kernel/kernel.c
- src/kernel/kernel.h
- src/arch/x86_64/boot_entry.c
- src/arch/x86_64/README.md
- docs/03-design/minimal-kernel-structure.md

## Planned Flow

Limine will eventually load the kernel.

The architecture-specific entry point will start first.

Then it will call the generic kernel main function.

Planned flow:

Limine
↓
_start
↓
kernel_main
↓
NucleOS kernel logic

## Today's Result

The first minimal kernel structure was created.

NucleOS now has source files that define where kernel execution will begin in the future.

## Reflection

This is the first step where NucleOS starts to move from documentation into actual source code.

The project still does not boot yet.

But now it has a foundation for the first bootable kernel.
