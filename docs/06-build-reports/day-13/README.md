# Day 13 verification evidence

Verification performed on October 31, 2026 on branch `codex/day13-audit`.

[results.json](results.json) records exact argument arrays, working directories
and exit codes. Each step has separate stdout and stderr captures. Trailing
spaces were removed from four lines of the saved readelf stdout for Git whitespace
hygiene; no diagnostic content was changed:

| Step | stdout | stderr |
| --- | --- | --- |
| Full kernel build | [kernel](kernel-stdout.txt) | [kernel](kernel-stderr.txt) |
| ISO creation | [iso](iso-stdout.txt) | [iso](iso-stderr.txt) |
| ELF inspection | [readelf](readelf-stdout.txt) | [readelf](readelf-stderr.txt) |
| Headless BIOS boot | [qemu](qemu-stdout.txt) | [qemu](qemu-stderr.txt) |

The [E9 trace](e9.txt) was copied from this QEMU run's output file.

## Source isolation

A new `build/day13-final-verification/source/` directory was populated from
`git ls-files --cached --others --exclude-standard -z` in the active worktree.
[Source files](source-files.txt) lists the copied inputs. This includes reviewed
uncommitted Day 13 files and worktree contents, not just HEAD. Ignored downloads,
old outputs, ISO staging directories and nested Limine source were excluded.
The current report directory was created after copying, so it is not in that
snapshot. Later documentation updates do not change the build inputs.

Python `subprocess.run(..., capture_output=True)` executed each command with
separate streams and saved its `returncode`; no shell pipeline masked failures.

The kernel build uses `make -B all` in the fresh source tree. The subsequent
`make iso` reuses those objects and records ISO-tool diagnostics separately.
Kernel stderr is empty and its exit code is 0: no GCC or GNU ld warnings were
emitted by this invocation. This statement concerns the current flags, not all
possible compiler diagnostics. ISO stderr contains xorriso progress and Limine
hybrid-table/active-partition diagnostics; it is not empty and must not be
reported as a warning-free run of every tool.

QEMU is bounded by `timeout 15s`; status 124 records planned termination.
The complete E9 sequence supplies boot-path evidence. After these tests, the
user confirmed on October 31, 2026 that QEMU displayed `WELCOME TO NUCLEOS`.
This is a user report, not an agent visual inspection or screenshot. No UEFI or
committed clean-clone test is claimed.
