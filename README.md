# NucleOS

NucleOS is an educational operating system project built from scratch to understand how computers work at a low level.

The goal of this project is not to replace Linux or create a production-ready operating system.

The goal is to learn operating system fundamentals through practice, documentation, experimentation, and visible technical progress.

## Current Status

NucleOS currently reaches its first real boot path through QEMU and Limine.

Current milestone:

```text
QEMU
↓
Limine
↓
NucleOS boot entry
↓
kernel.elf
↓
black screen
```

The black screen is expected at this stage because the kernel does not have a text output system yet.

Next goal:

```text
Display "Welcome to NucleOS" from the kernel.
```

## Project Goals

- Understand the boot process.
- Build a basic x86_64 kernel.
- Run the system inside QEMU.
- Learn low-level C programming.
- Study x86_64 architecture.
- Understand linker scripts and ELF binaries.
- Learn bootloader integration with Limine.
- Study memory management.
- Learn interrupts and basic hardware interaction.
- Build a minimal shell.

## Development Environment

- Host OS: Linux Mint 22.3
- Target architecture: x86_64
- Main language: C
- Assembly: NASM
- Emulator: QEMU
- Bootloader: Limine
- Build system: Make
- Linker: GNU ld
- ISO creation: xorriso
- Debugger: GDB
- Documentation: Obsidian and Markdown
- Visual notes: Xournal++

## Project Structure

```text
NucleOS/
├── boot/
│   └── limine.conf
├── docs/
│   ├── 01-daily-log/
│   ├── 02-concepts/
│   ├── 03-design/
│   ├── 04-xournal/
│   └── 06-build-reports/
├── iso_root/
├── scripts/
├── src/
│   ├── kernel/
│   └── arch/
│       └── x86_64/
├── tools/
│   └── limine/
├── Makefile
├── linker.ld
└── README.md
```

## Build Commands

Build the kernel ELF file:

```bash
make
```

Create the bootable ISO candidate:

```bash
make iso
```

Run NucleOS in QEMU:

```bash
make run
```

Clean generated build artifacts:

```bash
make clean
```

## Development Timeline

### Day 0 — Project Start

Initialized the NucleOS project, created the repository structure, and prepared the Linux study environment.

### Day 1 — Boot Process

Studied the basic boot process and documented how a machine moves from firmware to bootloader to kernel.

### Day 2 — Limine and QEMU Plan

Planned the boot flow using Limine and QEMU.

### Day 3 — Minimal Kernel Structure

Created the first kernel source structure:

```text
src/kernel/
src/arch/x86_64/
```

### Day 4 — Linker Script and Build Plan

Documented how source files become object files and how the linker produces a kernel ELF file.

### Day 5 — First Linker Script and Makefile

Created the first `linker.ld` and `Makefile`.

Generated:

```text
build/kernel.elf
```

### Day 6 — Inspecting the Kernel ELF

Inspected `kernel.elf` using:

```text
file
readelf
nm
objdump
```

Confirmed important symbols such as:

```text
_start
kernel_main
```

### Day 7 — Limine ISO Structure

Prepared the first ISO root structure and Limine configuration.

### Day 8 — Limine Integration

Downloaded and integrated Limine bootloader files into the project.

### Day 9 — First Bootable ISO Workflow

Created the first ISO generation workflow using `xorriso` and Limine.

Generated:

```text
build/nucleos.iso
```

### Day 10 — First QEMU Boot Attempt

Ran the first real QEMU boot attempt.

Important results:

- QEMU booted the ISO.
- Limine appeared.
- The NucleOS boot entry appeared.
- Limine found `kernel.elf`.
- The lower-half ELF issue was fixed.
- The system now reaches a black screen after selecting NucleOS.

Current interpretation:

The kernel is likely being loaded and entered, but it does not display anything yet because no text output system exists.

## Documentation Workflow

NucleOS uses a documentation-first workflow:

```text
Markdown / Obsidian = technical documentation
Xournal++ = diagrams, examples, sketches, handwritten notes
GitHub = public evidence of progress
```

Every important day should include:

- daily log
- concept notes
- design notes
- Xournal++ visual notes
- PDF exports for easy viewing on GitHub
- Git commits with clear messages

## Learning Sources and References

The following resources are used as study references during the development of NucleOS.

### OS Development

- OSDev Wiki — Main Page  
  https://wiki.osdev.org/Main_Page

- OSDev Wiki — Limine Bare Bones  
  https://wiki.osdev.org/Limine_Bare_Bones

- OSDev Wiki — Bare Bones  
  https://wiki.osdev.org/Bare_Bones

- OSDev Wiki — Higher Half Kernel  
  https://wiki.osdev.org/Higher_Half_Kernel

- OSDev Wiki — Linker Scripts  
  https://wiki.osdev.org/Linker_Scripts

- OSDev Wiki — ELF  
  https://wiki.osdev.org/ELF

### Computer Architecture and Systems Learning

- Nand2Tetris — Building a Modern Computer From First Principles  
  https://www.nand2tetris.org/

- Nand2Tetris Projects  
  https://www.nand2tetris.org/course

### Bootloader

- Limine GitHub Repository  
  https://github.com/limine-bootloader/limine

- Limine Website  
  https://limine-bootloader.org/

### Emulation

- QEMU Documentation  
  https://www.qemu.org/docs/master/system/

### Build Tools

- GNU Make Manual  
  https://www.gnu.org/software/make/manual/make.html

- GCC Online Documentation  
  https://gcc.gnu.org/onlinedocs/

- GNU ld Documentation  
  https://sourceware.org/binutils/docs/ld/

- GNU Binutils Documentation  
  https://sourceware.org/binutils/docs/

- xorriso Manual  
  https://www.gnu.org/software/xorriso/man_1_xorriso.html

### Debugging and Assembly

- GDB Documentation  
  https://sourceware.org/gdb/current/onlinedocs/gdb.html

- NASM Documentation  
  https://www.nasm.us/docs.php

### Operating Systems Theory

- Operating Systems: Three Easy Pieces  
  https://pages.cs.wisc.edu/~remzi/OSTEP/

## Learning Philosophy

Small technical progress + clear documentation.

NucleOS is part of a larger learning path.

Together with other projects, it aims to build a deeper understanding of computing from hardware to software.

## Safety Notice

NucleOS is tested only inside QEMU.

The ISO is not written to a real disk.

The real laptop boot system is not modified.
