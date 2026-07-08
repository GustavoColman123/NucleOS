# Day 11 Sources

These are the main sources and references used during Day 11.

## Limine Source and Test Files

The Limine source tree was inspected to understand request sections, request IDs, framebuffer requests, and linker behavior.

### Limine Test Kernel

Used to study how Limine requests are declared.

Relevant ideas:

- `.limine_requests`
- `LIMINE_FRAMEBUFFER_REQUEST_ID`
- request structs
- request responses

Source:

https://github.com/limine-bootloader/limine/blob/trunk/test/limine.c

## Limine Test Linker Script

Used to study how Limine request sections are preserved.

Relevant ideas:

- `.limine_requests_start_marker`
- `.limine_requests`
- `.limine_requests_end_marker`
- `KEEP(...)`

Source:

https://github.com/limine-bootloader/limine/blob/trunk/test/linker.ld

## Limine Protocol Implementation

Used to understand how Limine loads kernels and how it expects higher-half executable mappings.

Relevant ideas:

- executable loading
- higher-half virtual addresses
- PHDR validation

Source:

https://github.com/limine-bootloader/limine/blob/trunk/common/protos/limine.c

## OSDev Wiki

Used as background reference for OS development concepts.

Relevant topics:

- boot process
- linker scripts
- ELF binaries
- higher-half kernels
- bare bones kernel structure

Sources:

https://wiki.osdev.org/Main_Page

https://wiki.osdev.org/Bare_Bones

https://wiki.osdev.org/Limine_Bare_Bones

https://wiki.osdev.org/Higher_Half_Kernel

https://wiki.osdev.org/Linker_Scripts

https://wiki.osdev.org/ELF

## QEMU

Used for virtual machine boot testing and E9 debug output.

Relevant usage:

qemu-system-x86_64 -cdrom build/nucleos.iso \
    -debugcon file:build/e9.log \
    -global isa-debugcon.iobase=0xe9

Source:

https://www.qemu.org/docs/master/system/

## Nand2Tetris

Used as a broader computer systems learning reference.

This source supports the long-term goal of understanding computing from lower-level abstractions upward.

Source:

https://www.nand2tetris.org/

## Operating Systems: Three Easy Pieces

Used as an operating systems theory reference.

Source:

https://pages.cs.wisc.edu/~remzi/OSTEP/
