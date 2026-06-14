# Day 7 Xournal++ Diagram Plan

## Title

NucleOS — Day 7: Limine and ISO Structure

## Diagram to Draw

build/kernel.elf
↓
iso_root/boot/kernel.elf

boot/limine.conf
↓
iso_root/limine.conf

iso_root/
↓
future ISO
↓
QEMU
↓
Limine
↓
NucleOS Kernel

## Side Notes

kernel.elf is the kernel binary.

limine.conf tells Limine what kernel to load.

iso_root becomes the future ISO contents.

## Goal

Show how NucleOS prepares the files needed for a future bootable ISO.
