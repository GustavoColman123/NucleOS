# Build System

A build system automates the process of compiling and linking a project.

For NucleOS, the planned build system is Make.

## Why Use Make?

Without Make, every build would require writing long compiler and linker commands manually.

Make allows the project to define rules.

These rules explain how to build the kernel.

## Planned Build Steps

1. Compile C source files.
2. Create object files.
3. Link object files using a linker script.
4. Produce kernel.elf.
5. Prepare ISO structure.
6. Run QEMU.

## Planned Tool

NucleOS will use:

Makefile

## First Build Target

The first important Makefile target will probably be:

make

This should build the kernel.

## Future Targets

Possible future targets:

make clean

Removes build files.

make run

Builds and runs NucleOS in QEMU.

make iso

Creates a bootable ISO.

make debug

Runs QEMU with debugging support.

## Design Rule

The build system should stay simple at the beginning.

A simple working build is better than a complex broken build.
