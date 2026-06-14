# Limine

Limine is the planned bootloader for NucleOS.

A bootloader is responsible for loading the kernel into memory and transferring control to it.

## Role in NucleOS

Limine will load the NucleOS kernel.

This allows the project to focus on kernel development instead of writing a complete bootloader from scratch at the beginning.

## Why Use a Bootloader?

A kernel cannot simply run by itself when the computer starts.

Before the kernel runs, something must:

- Prepare the boot environment
- Load the kernel file
- Provide useful boot information
- Jump to the kernel entry point

That is the bootloader's job.

## Why Limine for NucleOS?

Limine is useful for this project because it supports modern operating system development workflows.

For NucleOS, Limine will help with the first major milestone:

Booting a custom kernel in QEMU.

## Planned Flow

QEMU starts a virtual machine.

Limine runs as the bootloader.

Limine loads the NucleOS kernel.

The NucleOS kernel starts executing.

## First Goal

The first goal is not advanced hardware support.

The first goal is simply:

NucleOS boots and prints a message.
