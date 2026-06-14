# NucleOS — Day 1: Understanding the Boot Process

## Date

June 14, 2026

## Goal

Understand what happens before the kernel starts running.

The goal of this session is not to write kernel code yet.

The goal is to understand the path from powering on a computer to loading the operating system kernel.

## Main Idea

A computer does not start by running the operating system directly.

Before the kernel can run, several steps happen:

1. The machine receives power.
2. The CPU begins execution from a predefined reset state.
3. The firmware starts.
4. The firmware initializes basic hardware.
5. The firmware searches for a bootable device.
6. A bootloader is loaded.
7. The bootloader loads the kernel.
8. The kernel starts running.

## Boot Process Overview

Power Button
↓
CPU Reset
↓
Firmware / BIOS / UEFI
↓
Boot Device
↓
Bootloader
↓
Kernel
↓
NucleOS

## Key Concepts

### Firmware

Firmware is low-level software stored on the motherboard.

It runs before the operating system and prepares the machine to boot.

### BIOS

BIOS is an older firmware interface used by many older PCs.

### UEFI

UEFI is the modern firmware interface used by most modern computers.

It replaces many limitations of BIOS.

### Bootloader

A bootloader is a small program responsible for loading the kernel into memory.

For NucleOS, the planned bootloader is Limine.

### Kernel

The kernel is the core of the operating system.

It controls hardware, memory, interrupts, processes, and system resources.

## NucleOS Direction

NucleOS will not be installed directly on the main laptop.

NucleOS will run inside QEMU.

This keeps the host Linux system safe.

## Today's Result

Today I studied and documented the boot process.

I now understand that the kernel does not run immediately when the computer turns on.

The firmware and bootloader are required before NucleOS can start.

## Reflection

Before writing kernel code, I need to understand how the kernel is reached.

This session helped define the first technical path of NucleOS:

Firmware loads the bootloader.

The bootloader loads the kernel.

The kernel becomes NucleOS.
