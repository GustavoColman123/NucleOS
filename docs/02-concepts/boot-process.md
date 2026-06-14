# Boot Process

The boot process is the sequence of events that happens when a computer starts.

An operating system does not begin running immediately.

Before the kernel can execute, the machine must pass through firmware and a bootloader.

## Simplified Flow

Power Button
↓
CPU Reset
↓
Firmware / BIOS / UEFI
↓
Boot Device Selection
↓
Bootloader
↓
Kernel Loaded Into Memory
↓
Kernel Entry Point
↓
Operating System Starts

## CPU Reset

When the computer receives power, the CPU begins from a predefined reset state.

At this stage, there is no operating system running yet.

The CPU starts executing firmware code.

## Firmware

Firmware is low-level software stored on the motherboard.

Its job is to initialize enough hardware to begin the boot process.

Modern machines usually use UEFI.

Older systems used BIOS.

## BIOS

BIOS stands for Basic Input/Output System.

It is an older firmware system.

BIOS searches for bootable devices and loads the first boot sector from a disk.

## UEFI

UEFI stands for Unified Extensible Firmware Interface.

It is the modern replacement for BIOS.

UEFI can understand filesystems and load bootloader files from an EFI system partition.

## Bootloader

The bootloader is responsible for loading the operating system kernel.

The bootloader prepares the environment and jumps to the kernel entry point.

For NucleOS, the planned bootloader is Limine.

## Kernel Entry Point

The kernel entry point is the first function or instruction where the kernel begins execution.

Once the bootloader jumps to the kernel, the operating system starts taking control.

## NucleOS Boot Plan

NucleOS will use QEMU for testing.

NucleOS will use Limine as the bootloader.

The first major technical milestone will be:

NucleOS boots in QEMU and displays a welcome message.

## Important Rule

Do not install NucleOS directly on the main laptop.

Run NucleOS inside QEMU during development.
