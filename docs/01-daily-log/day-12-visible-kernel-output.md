# NucleOS — Day 12: Visible Kernel Output

## Date

July 8, 2026

## Goal

The goal of Day 12 was to make NucleOS display visible text from the kernel.

The target message was:

WELCOME TO NUCLEOS

## Context

Day 11 confirmed that the kernel was executing, but the screen remained black.

The E9 debug log from Day 11 proved that:

- `kernel_main` was reached.
- `terminal_init()` executed.
- `terminal_write()` executed.
- The kernel reached the halt loop.

However, visible text output had not been achieved yet.

## Key Problem

The framebuffer request was not being recognized by Limine.

The Day 11 debug log showed:

[NO_FRAMEBUFFER_RESPONSE]

This meant that the kernel was running, but Limine was not providing a framebuffer response.

## Investigation

The Limine source and protocol headers were inspected.

The important discovery was that the framebuffer request ID must include `LIMINE_COMMON_MAGIC`.

The correct structure is:

LIMINE_COMMON_MAGIC
+
0x9d5827dcd881dd75
+
0xa3148604f6fab11b

The previous custom request ID was incorrect.

Because of that, Limine did not recognize the framebuffer request.

## Fix

The custom `src/limine.h` header was corrected.

The framebuffer request ID was updated to use:

LIMINE_FRAMEBUFFER_REQUEST_ID

with:

LIMINE_COMMON_MAGIC

After this correction, Limine successfully responded to the framebuffer request.

## Kernel Output Path

The final output path is:

QEMU
↓
Limine
↓
NucleOS boot entry
↓
kernel.elf
↓
kernel_main
↓
Limine framebuffer response
↓
terminal_init
↓
terminal_write
↓
WELCOME TO NUCLEOS

## Successful E9 Debug Log

After the fix, the debug log showed:

[KERNEL_MAIN_ENTERED]
[FRAMEBUFFER_RESPONSE_OK]
[FRAMEBUFFER_COUNT_OK]
[FRAMEBUFFER_POINTER_OK]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]

## Visual Result

The QEMU window displayed:

WELCOME TO NUCLEOS

This is the first successful visible text output from the NucleOS kernel.

## Technical Status

Successful:

- The kernel enters `kernel_main`.
- E9 debug output works.
- Limine framebuffer request works.
- A framebuffer response is received.
- A valid framebuffer pointer is available.
- The terminal initializes using the framebuffer.
- The kernel renders text visibly on screen.
- QEMU displays `WELCOME TO NUCLEOS`.

## Why This Matters

This is one of the most important milestones so far.

Before this day, NucleOS could boot into a black screen.

After this day, NucleOS can visibly prove that its kernel is running.

The project moved from invisible execution to visible kernel output.

## Relationship to Day 11

Day 11 was difficult, frustrating, and exhausting.

However, Day 11 was necessary.

The E9 debug output from Day 11 proved that the kernel was running and helped isolate the real issue.

Day 12 succeeded because Day 11 turned a black screen into a diagnosable problem.

## Next Step

The next goal is to improve the terminal system.

Possible improvements:

- Add newlines.
- Add cursor movement.
- Add more glyphs.
- Add numbers and punctuation.
- Print debug information such as framebuffer width, height, pitch, and bpp.
- Improve documentation and visual diagrams.
