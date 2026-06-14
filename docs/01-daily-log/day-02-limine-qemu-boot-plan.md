# NucleOS — Day 2: Limine and QEMU Boot Plan

## Date

June 14, 2026

## Goal

Understand how NucleOS will be loaded and tested.

The goal of this session is not to write the kernel yet.

The goal is to define the first boot strategy using Limine and QEMU.

## Main Idea

NucleOS will not be installed directly on the main laptop.

Instead, it will run inside QEMU.

QEMU will emulate a computer.

Limine will act as the bootloader.

Limine will load the NucleOS kernel.

The kernel will eventually print a first message:

Welcome to NucleOS

## Planned Boot Flow

QEMU
↓
Virtual Machine
↓
Limine Bootloader
↓
NucleOS Kernel
↓
Welcome to NucleOS

## Why QEMU?

QEMU allows NucleOS to run in a safe virtual environment.

This protects the host Linux system.

If NucleOS crashes, only the emulated machine crashes.

The real laptop stays safe.

## Why Limine?

Limine is a modern bootloader suitable for educational operating system development.

It can load a custom kernel and prepare the system before transferring control to it.

For NucleOS, Limine will help avoid writing a full bootloader from scratch at the beginning.

## First Technical Milestone

The first major milestone will be:

NucleOS boots in QEMU and displays:

Welcome to NucleOS

## Files We Will Eventually Need

The first bootable version of NucleOS will likely need:

- Kernel source code
- Linker script
- Limine configuration
- Build script or Makefile
- Bootable ISO structure
- QEMU run command

## Today's Result

Today I defined the first boot strategy for NucleOS.

NucleOS will be tested in QEMU and loaded by Limine.

## Reflection

Day 1 explained the general boot process.

Day 2 connects that theory to the actual NucleOS development plan.

The next step will be preparing the first minimal bootable kernel structure.
