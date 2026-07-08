# NucleOS — Day 11: Kernel Execution Debugging

## Date

July 8, 2026

## Goal

The original goal of this day was to make the kernel display visible text on screen.

The intended message was:

WELCOME TO NUCLEOS

## Context

Day 10 ended with a black screen after selecting the NucleOS boot entry in Limine.

At that point, the main question was:

Is the kernel actually running, or is the boot process silently failing before `kernel_main`?

Day 11 focused on answering that question.

## Emotional Context

This was one of the most difficult days so far.

There were many compilation errors, wrong assumptions, failed attempts, black screens, and unclear results.

The process was frustrating and mentally exhausting.

However, the day was still productive because each failure reduced uncertainty.

The important lesson was patience:

A black screen does not automatically mean failure.

Sometimes it means the system is running, but there is no output mechanism yet.

## First Attempt: Limine Framebuffer Output

The first strategy was to request a framebuffer from Limine and draw text directly to the screen.

The plan was:

Limine
↓
framebuffer request
↓
kernel_main
↓
terminal_init
↓
terminal_write
↓
WELCOME TO NUCLEOS

This required adding a minimal Limine protocol header and creating a framebuffer-based terminal.

## Problem: Wrong Limine Header

A header file from the Limine source tree was initially copied, but it was not the correct standalone protocol header for kernel requests.

This caused many compiler errors related to undefined or incomplete types, such as:

- `struct limine_framebuffer_request`
- `LIMINE_FRAMEBUFFER_REQUEST`
- `LIMINE_BASE_REVISION`
- `LIMINE_REQUESTS_START_MARKER`

This showed that the wrong header was being used.

## Limine Request Investigation

The Limine source and test files were inspected to understand how requests are declared.

Important findings:

- Limine requests use a dedicated `.limine_requests` section.
- Request markers use `.limine_requests_start_marker` and `.limine_requests_end_marker`.
- The framebuffer request uses `LIMINE_FRAMEBUFFER_REQUEST_ID`.
- The linker script must preserve Limine request sections with `KEEP(...)`.

This helped correct the request section names and improve the linker script.

## Second Attempt: Minimal Limine Header

A small custom `src/limine.h` was created with only the required framebuffer structures and constants.

This allowed the kernel to compile again.

However, QEMU still showed a black screen.

At this stage, the kernel still had no visible screen output.

## Debug Strategy: E9 Output

To avoid guessing, an E9 debug output channel was added.

QEMU was launched with:

qemu-system-x86_64 -cdrom build/nucleos.iso \
    -debugcon file:build/e9.log \
    -global isa-debugcon.iobase=0xe9

The kernel wrote debug messages to I/O port `0xE9`.

This allowed the kernel to leave evidence in:

build/e9.log

## E9 Debug Result

The debug log showed:

[KERNEL_MAIN_ENTERED]
[NO_FRAMEBUFFER_RESPONSE]
[HALT]

This confirmed that:

- Limine loaded the kernel.
- The kernel entered `kernel_main`.
- The framebuffer response was not available.
- The kernel reached the halt loop.

This was an important breakthrough.

The kernel was running.

The problem was no longer kernel loading.

The problem was output visibility.

## Third Attempt: VGA Text Mode

After framebuffer output failed, VGA text mode output was attempted using memory address:

0xB8000

The kernel wrote to VGA memory and the debug log later showed:

[KERNEL_MAIN_ENTERED]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]

This confirmed that:

- `kernel_main` executed.
- `terminal_init()` executed.
- `terminal_write()` executed.
- The kernel reached the halt loop.

However, the text was still not visible in the QEMU window.

## Interpretation

The VGA text mode code executed, but the current boot environment did not show traditional VGA text output.

This means that the output function ran, but the display mode was not compatible with the method used.

The screen remained black, but the debug log proved execution.

## Day 11 Result

The original visible text goal was not achieved yet.

WELCOME TO NUCLEOS did not appear on screen.

However, Day 11 achieved a major debugging milestone:

NucleOS kernel execution was confirmed through E9 debug output.

This means the project now has evidence that the kernel is not merely being loaded.

The kernel is executing its own code.

## Technical Status

Successful:

- `kernel_main` is reached.
- E9 debug output works.
- The kernel can write debug traces to `build/e9.log`.
- `terminal_init()` runs.
- `terminal_write()` runs.
- The halt loop is reached intentionally.

Still unresolved:

- Limine framebuffer response is not available yet.
- VGA text output executes but is not visible.
- No visible screen text yet.

## Important Lesson

This day showed why kernel development requires patience.

A black screen can hide many different states.

Without debug output, every failure looks the same.

With E9 debug output, the black screen became diagnosable.

## Next Step

Day 12 will focus on producing reliable visible output.

The main goal remains:

WELCOME TO NUCLEOS

Day 12 will also include a stronger Xournal++ visual summary covering both Day 11 and Day 12.

## Xournal++ Note

Day 11 does not include Xournal++ notes.

This was intentional.

Because the day was difficult and heavily focused on debugging, the visual summary is reserved for Day 12.

Day 12 should include a higher-quality Xournal++ explanation covering both Day 11 and Day 12.
