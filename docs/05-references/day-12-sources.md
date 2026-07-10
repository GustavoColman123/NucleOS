# Day 12 Sources

These are the main sources and references used during Day 12.

## Limine Protocol Header

Used to verify the correct framebuffer request ID structure.

Important discovery:

`LIMINE_FRAMEBUFFER_REQUEST_ID` must include `LIMINE_COMMON_MAGIC`.

Relevant concepts:

- `LIMINE_COMMON_MAGIC`
- `LIMINE_FRAMEBUFFER_REQUEST_ID`
- `struct limine_framebuffer`
- `struct limine_framebuffer_response`
- `struct limine_framebuffer_request`

Reference:

https://github.com/managarm/managarm/blob/d8e7e178bb21573d5cc040b8c46d4d80500ca2b2/kernel/eir/boot/limine/limine.h

## Limine Test Kernel

Used to understand how framebuffer requests are declared in a working Limine test environment.

Reference:

https://github.com/limine-bootloader/limine/blob/trunk/test/limine.c

## Limine Test Linker Script

Used to understand how Limine request sections are preserved.

Reference:

https://github.com/limine-bootloader/limine/blob/trunk/test/linker.ld

## QEMU

Used to boot the ISO and verify visible output.

Also used with E9 debug output:

qemu-system-x86_64 -cdrom build/nucleos.iso \
    -debugcon file:build/e9.log \
    -global isa-debugcon.iobase=0xe9

Reference:

https://www.qemu.org/docs/master/system/

## OSDev Wiki

Used as background reference for OS development concepts.

References:

https://wiki.osdev.org/Main_Page

https://wiki.osdev.org/Limine_Bare_Bones

https://wiki.osdev.org/Higher_Half_Kernel

https://wiki.osdev.org/ELF
