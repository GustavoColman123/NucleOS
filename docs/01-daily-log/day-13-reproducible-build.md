# NucleOS — Day 13: Reproducible build recovery

## Date

October 31, 2026

## Goal

Reproduce Day 12 from repository-contained inputs without relying on ignored
local downloads or generated artifacts. Work remains on `codex/day13-audit`.

## Changes

- Added exact ignore exceptions for the BIOS and UEFI Limine CD images.
- Included the existing local images without changing Limine 12.3.3.
- Preserved the complete Limine redistribution license beside its assets.
- Recorded the six asset hashes and local provenance in
  [the Limine manifest](../../tools/limine/README.md).
- Added [setup instructions](../setup.md), converted the documentation index
  to GitHub-compatible links, and marked obsolete design snapshots as historical.
- Corrected the README boot ordering. Earlier daily logs were left unchanged.

The local license permits source and binary redistribution subject to retention
of its copyright, conditions and disclaimer. Keep these materials with the
assets and include the license when distributing an ISO separately.

## Verification

Created `build/day13-source-audit/` using only `git ls-files` contents and the
explicit new Day 13 input files. No ignored build output, ISO staging tree or
`tools/downloads/` directory was copied. The only previously ignored inputs
included were the two authorized boot images, now visible as untracked files.
This candidate source snapshot was created before this daily log existed; the
log is documentation, not a build input.

Executed from the repository root:

```sh
make -B iso BUILD_DIR=output ISO_ROOT=output/iso_root -C build/day13-source-audit
readelf -h -l build/day13-source-audit/output/kernel.elf
timeout 15s qemu-system-x86_64 \
  -cdrom build/day13-source-audit/output/nucleos.iso -boot d -display none \
  -no-reboot -no-shutdown \
  -debugcon file:build/day13-source-audit/output/e9.log \
  -global isa-debugcon.iobase=0xe9
```

Results:

- Full compilation and ISO creation succeeded; no GCC or GNU ld warnings.
- Limine reported successful BIOS stage installation. Its hybrid-table conversion
  and active-partition messages concerned the generated ISO file only.
- ELF: x86_64 EXEC, entry `0xffffffff800003f0`, three LOAD segments with
  R/E, R and R/W permissions.
- QEMU BIOS boot produced every expected E9 marker:

```text
[KERNEL_MAIN_ENTERED]
[FRAMEBUFFER_RESPONSE_OK]
[FRAMEBUFFER_COUNT_OK]
[FRAMEBUFFER_POINTER_OK]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]
```

The headless QEMU run ended with timeout status 124 after 15 seconds as planned;
this was not a boot failure. A separate graphical QEMU instance was opened using
the same candidate ISO, and human visual confirmation was requested.
At that stage visual confirmation was pending; E9 alone does not prove visible rendering.

Asset SHA-256 checks passed. Protected kernel sources and linker script match
HEAD byte for byte. No packages were installed, no downloads performed and no
commit, push or merge was made during those verification steps.

## Follow-up review and captured evidence

The independent review reported approval with observations. The documentation
index now covers all existing concepts, designs, visual sources and PDF exports,
including the Days 10–12 additions and this Day 13 log. No Day 11 or Day 13
visual artifacts were invented. Link labels and visual-format tables are uniform.
The README tree distinguishes repository inputs from generated/ignored material.

The ignored local Limine source has HEAD `86571ed`, with a ChangeLog headed
`Release 12.4.0`, and no local tag exactly at HEAD. It is separate from the
vendored 12.3.3 binaries and is not a build dependency. Its contents cannot prove
compatibility with or provenance of those binaries. The original binary archive
URL, exact release tag and authenticity remain unverified; the project homepage
is not a download provenance claim.

A second isolated candidate snapshot was created at
`build/day13-final-verification/source/`, using worktree files selected by
`git ls-files --cached --others --exclude-standard -z`. The
[verification report](../06-build-reports/day-13/README.md) includes the file list,
exact commands, stdout, stderr and exit codes.

- `make -B all`: exit 0; kernel stderr empty (0 bytes), no GCC/ld warnings emitted.
- `make iso`: exit 0; ISO generated and BIOS stages installed. ISO stderr is
  nonempty: xorriso progress and Limine hybrid-table/active-partition diagnostics
  are preserved rather than described as absent.
- `readelf -h -l`: exit 0; x86_64 EXEC, higher-half entry, three LOAD segments.
- Headless BIOS QEMU: complete E9 sequence; timeout exit 124 after 15 seconds.

The documented explicit QEMU command uses an existing ISO and adds boot-order
and no-reboot/no-shutdown flags; `make run` regenerates the ISO and omits those
flags. The headless test additionally disables the display and bounds runtime.
The Makefile was not changed.

All files under `src/`, `Makefile`, `linker.ld` and earlier daily logs were checked
byte for byte against HEAD. Only documentation changed during this follow-up.
The previous graphical launch and its E9 success do not constitute human visual
confirmation. The user subsequently supplied that confirmation, as recorded below.

## Limits and next step

The isolated candidate build demonstrates independence from the ignored local
inputs excluded above. It is not a fresh clone of a committed Day 13 revision:
the tests preceded the authorized local Day 13 commit. At that stage a clean
checkout of the commit had not been tested; see the subsequent audit below. UEFI boot and byte-for-byte ISO reproducibility were
not tested. The bundled host utility is specific to Linux x86_64; the original
archive's authenticity was not independently verified.

## User visual confirmation

On October 31, 2026, the user confirmed that QEMU displayed
`WELCOME TO NUCLEOS`. This records the user's observation; it is not a screenshot
or visual inspection performed by the agent. The user authorized the local
commit `Make NucleOS build reproducible (Day 13)`. At that stage no push or merge
was authorized.

A subsequent independent audit by Claude Code, reported by the user, tested a
clean clone of commit `e8627b5a0aba35426cba221715df46a248e9986b`: compilation
without warnings, ISO creation, BIOS QEMU boot and all seven E9 markers passed.
The surviving clone is clean and points to that commit. A real QEMU `screendump`
PNG from its logs is preserved with its hash in the
[verification report](../06-build-reports/day-13/README.md#independent-clean-clone-audit-and-framebuffer-evidence).
The agent inspected the saved image; it displays `WELCOME TO NUCLEOS`.
This is additional evidence from Claude Code's run, not a new execution by this
agent. The user subsequently authorized publication of the branch and a PR,
without merging or modifying main.

UEFI boot, byte-for-byte ISO reproducibility and the original Limine archive's
authenticity remain unverified.
