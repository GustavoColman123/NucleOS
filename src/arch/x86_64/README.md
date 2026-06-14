# x86_64 Architecture Layer

This directory contains architecture-specific code for the x86_64 version of NucleOS.

## Purpose

The architecture layer is responsible for low-level details that depend on the CPU architecture.

Examples:

- kernel entry point
- CPU instructions
- interrupt setup
- paging setup
- hardware-specific initialization

## Initial File

boot_entry.c

This file defines the `_start` function.

The `_start` function will eventually be called after the bootloader loads the kernel.
