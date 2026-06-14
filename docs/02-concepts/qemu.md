# QEMU

QEMU is the emulator that will be used to run NucleOS safely.

NucleOS will not be installed directly on the main laptop.

It will run inside an emulated machine.

## Role in NucleOS

QEMU provides a virtual computer where NucleOS can boot.

This allows testing without risking the host Linux system.

## Why Use QEMU?

QEMU is useful because:

- It runs operating systems in a controlled environment.
- It allows fast testing.
- It protects the real machine.
- It makes debugging easier.
- It can emulate x86_64 hardware.

## Safety Rule

Do not install NucleOS on the real laptop.

Do not modify real boot partitions.

Do not overwrite real disks.

During development, NucleOS runs in QEMU.

## Planned First Command

Eventually, NucleOS will be tested with a command similar to:

qemu-system-x86_64 -cdrom build/nucleos.iso

This command will boot a generated ISO inside QEMU.

## First Goal

The first goal is:

Start QEMU.

Load Limine.

Load the NucleOS kernel.

Print a welcome message.
