# First QEMU Boot Attempt

## Objective

Document the first attempt to boot NucleOS inside QEMU.

## Input

build/nucleos.iso

## Command

qemu-system-x86_64 -cdrom build/nucleos.iso

## Expected Boot Chain

QEMU
↓
nucleos.iso
↓
Limine
↓
boot/kernel.elf
↓
NucleOS kernel

## Current Kernel Limitation

The current kernel does not have a screen output driver.

The kernel enters an infinite loop after startup.

Because of this, a successful kernel load may not show visible text yet.

## What Counts as Progress

Seeing Limine counts as progress.

Seeing a Limine error counts as useful diagnostic information.

Seeing QEMU open and attempt to boot the ISO counts as progress.

## Next Step

If the ISO boots into Limine, the next major task is adding visible kernel output.
