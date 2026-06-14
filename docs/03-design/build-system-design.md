# Build System Design

## Objective

Define the first build system for NucleOS.

The initial build system uses a Makefile to compile and link the minimal kernel.

## Main Output

The first output is:

build/kernel.elf

This file is the linked kernel binary.

It is not a complete bootable ISO yet.

## Tools

NucleOS currently uses:

- GCC
- LD
- Make
- linker.ld

## Build Pipeline

src/kernel/kernel.c
↓
build/kernel.o

src/arch/x86_64/boot_entry.c
↓
build/boot_entry.o

build/kernel.o + build/boot_entry.o
↓
linker.ld
↓
build/kernel.elf

## Makefile Targets

### make

Builds the kernel ELF file.

### make clean

Removes the build directory.

## Current Limitations

The current Makefile does not create an ISO.

The current Makefile does not run QEMU.

The current kernel does not print text yet.

The current kernel is not connected to Limine yet.

## Next Steps

Future build targets may include:

- make iso
- make run
- make clean
- make debug

## Design Rule

Start simple.

Build kernel.elf first.

Create the ISO and QEMU workflow later.
