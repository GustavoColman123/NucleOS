# NucleOS — Codex Rules

## Project purpose

NucleOS is an educational x86_64 operating-system project.

The primary goal is learning operating-system development, not maximizing development speed or generating large amounts of code automatically.

The human developer must be able to understand every important architectural change.

## Current architecture

- Architecture: x86_64
- Main languages: C and NASM
- Bootloader: Limine
- Build system: Make
- Linker: GNU ld
- Emulator: QEMU
- Debugging may use GDB, E9/debugcon, readelf, objdump, nm and similar development tools.

Do not replace these technologies or redesign the project unless explicitly requested.

## Safety — mandatory

- NEVER write to, format, mount, partition, overwrite, or otherwise modify real disks or block devices.
- NEVER run commands such as dd, mkfs, fdisk, parted, wipefs, or equivalent destructive disk utilities against real devices.
- NEVER install NucleOS onto the host computer.
- Boot and test NucleOS ONLY inside QEMU.
- Do not use sudo unless the human explicitly approves the exact command.
- Do not modify files outside this repository.
- Do not access unrelated files in the user's home directory.
- Do not push to GitHub unless explicitly requested.
- Do not rewrite Git history.
- Do not delete branches or tags.

## Development philosophy

Before changing code:

1. Inspect the existing implementation.
2. Understand the current boot and execution path.
3. Explain the likely cause of the issue or the purpose of the proposed change.
4. Prefer the smallest correct change.

After changing code:

1. Build the project.
2. Inspect compiler/linker errors and warnings.
3. Test using QEMU when appropriate.
4. Verify that existing functionality has not regressed.
5. Summarize what changed and why.

## Educational constraints

- Prefer understandable code over clever code.
- Explain OSDev concepts when they matter to a change.
- Do not hide important implementation details behind unnecessary abstractions.
- Do not generate a large subsystem unless explicitly requested.
- Do not silently change architecture or project conventions.
- Ask before making major design decisions.

## Current known milestone

The project has successfully reached:

QEMU
-> Limine
-> kernel.elf
-> kernel_main
-> Limine framebuffer
-> terminal initialization
-> visible framebuffer text

A visible message:

WELCOME TO NUCLEOS

has already been achieved.

E9/debugcon logging has also been used during development.

The next development work should build on the existing implementation rather than recreating it.

## Git workflow

The current Codex work must remain on the active development branch.

Before substantial modifications:

- inspect git status
- inspect relevant history when useful
- preserve existing working functionality

Do not commit unless explicitly asked.
