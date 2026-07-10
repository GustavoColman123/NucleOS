# Visible Kernel Output

## Objective

Design the first visible text output path for the NucleOS kernel.

## Final Day 12 Output Path

QEMU
↓
Limine
↓
kernel.elf
↓
kernel_main
↓
framebuffer request response
↓
terminal_init
↓
terminal_write
↓
WELCOME TO NUCLEOS

## Previous Problem

Day 11 confirmed that the kernel was running, but no text appeared on screen.

E9 debug output showed that the kernel reached the terminal code path.

The problem was output visibility.

## Root Cause

The custom Limine framebuffer request ID was incorrect.

Because of this, Limine did not recognize the request and did not provide a framebuffer response.

## Fix

The framebuffer request ID was corrected by using:

LIMINE_COMMON_MAGIC

inside:

LIMINE_FRAMEBUFFER_REQUEST_ID

## Terminal Renderer

The terminal renderer writes pixels directly to the framebuffer.

Current limitations:

- Only a small set of uppercase glyphs exists.
- Only one text color is used.
- Only one line is currently demonstrated.
- No scrolling exists yet.
- No formatted output exists yet.

## Debug Evidence

The successful debug log was:

[KERNEL_MAIN_ENTERED]
[FRAMEBUFFER_RESPONSE_OK]
[FRAMEBUFFER_COUNT_OK]
[FRAMEBUFFER_POINTER_OK]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]

## Visual Evidence

The QEMU screen displayed:

WELCOME TO NUCLEOS

## Current Conclusion

NucleOS now has reliable visible kernel output through the Limine framebuffer.
