# Day 10 Xournal++ Example Plan

## Title

QEMU Command Example

## Example to Draw

make run

means:

make iso
+
qemu-system-x86_64 -cdrom build/nucleos.iso

## Result

Limine boots.

NucleOS entry appears.

After selecting NucleOS, QEMU shows a black screen.

## Interpretation

The kernel likely loads, but it does not print anything yet.
