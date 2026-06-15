# QEMU Boot Testing

QEMU allows NucleOS to be tested inside a virtual machine.

This avoids modifying the real laptop boot system.

## Why QEMU Is Useful

QEMU is useful for operating system development because:

- It creates a virtual machine.
- It can boot ISO images.
- It is safer than testing on real hardware.
- It makes repeated experiments easier.
- If the kernel crashes, only the virtual machine crashes.

## NucleOS Usage

NucleOS uses QEMU to boot:

build/nucleos.iso

## Basic Command

qemu-system-x86_64 -cdrom build/nucleos.iso

## Expected Flow

QEMU starts.

QEMU loads the ISO.

Limine starts.

Limine reads limine.conf.

Limine loads the kernel.

The kernel begins execution.

## Important Note

The current kernel may not display anything yet.

A blank screen after loading the kernel does not always mean total failure.

It may mean the kernel is running but has no text output system yet.
