# Day 9 Xournal++ Diagram Plan

## Title

NucleOS — Day 9: First Bootable ISO

## Diagram to Draw

kernel.elf
+
limine.conf
+
Limine boot files
↓
iso_root/
↓
xorriso
↓
build/nucleos.iso
↓
Future QEMU boot

## Side Notes

kernel.elf is the NucleOS kernel.

limine.conf tells Limine what kernel to load.

xorriso creates the ISO image.

The ISO is still tested only in QEMU.

## Goal

Show how NucleOS becomes a bootable ISO image.
