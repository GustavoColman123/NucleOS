# E9 Debug Output

E9 debug output is a simple debugging technique used with QEMU.

It allows a kernel to write characters to I/O port:

0xE9

QEMU can capture those characters and save them into a file.

## Why It Matters

Early kernels often do not have normal debugging tools.

At this stage, NucleOS does not yet have:

- reliable screen output
- serial output
- keyboard input
- filesystem support
- a shell
- a debugger attached to the running kernel

Because of this, a black screen can be ambiguous.

E9 debug output helps distinguish between:

- the kernel not running
- the kernel running but not showing output
- the kernel halting intentionally
- a specific code path failing

## QEMU Command Used

qemu-system-x86_64 -cdrom build/nucleos.iso \
    -debugcon file:build/e9.log \
    -global isa-debugcon.iobase=0xe9

## NucleOS Debug Messages

During Day 11, NucleOS printed:

[KERNEL_MAIN_ENTERED]
[NO_FRAMEBUFFER_RESPONSE]
[HALT]

Later, after the VGA text mode attempt, it printed:

[KERNEL_MAIN_ENTERED]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]

## Interpretation

These messages proved that the kernel reached `kernel_main`.

They also proved that `terminal_init()` and `terminal_write()` were executed.

Even though no text appeared on the QEMU screen, the kernel was confirmed to be executing code.

## Role in NucleOS

E9 output is now a diagnostic tool for early boot debugging.

It should not replace real kernel output.

It is a temporary debugging channel until NucleOS has reliable visible output.
