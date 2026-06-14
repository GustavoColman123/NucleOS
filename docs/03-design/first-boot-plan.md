# NucleOS First Boot Plan

## Objective

Define the first bootable version of NucleOS.

The first version does not need memory management, interrupts, keyboard input, or a shell.

The first version only needs to boot and show a message.

## First Milestone

NucleOS boots in QEMU and displays:

Welcome to NucleOS

## Planned Components

The first bootable version will need:

- A minimal kernel written in C
- A kernel entry point
- A linker script
- A Limine configuration file
- A Makefile
- A bootable ISO image
- A QEMU run command

## Planned Directory Usage

boot/

This directory will contain bootloader-related files.

src/kernel/

This directory will contain generic kernel code.

src/arch/x86_64/

This directory will contain architecture-specific code.

scripts/

This directory may contain helper scripts.

tools/

This directory may contain external tools or downloaded bootloader files.

## First Boot Flow

QEMU starts.

Limine is loaded.

Limine loads the NucleOS kernel.

The kernel starts.

The kernel prints:

Welcome to NucleOS

## What This Version Will Not Have Yet

The first bootable version will not have:

- Memory manager
- Scheduler
- Filesystem
- User programs
- Drivers
- Shell
- Multitasking

## Design Rule

The first boot must be simple.

Boot first.

Add complexity later.
