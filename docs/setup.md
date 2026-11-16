# Build and boot NucleOS

This guide describes the Day 13 recovery baseline (2026-10-31): an x86_64
Linux host, GCC, GNU ld, Make, xorriso and QEMU. The expected output is
`WELCOME TO NUCLEOS` rendered by the kernel in QEMU.

## Dependencies

Verified locally: GCC 13.3.0 (`x86_64-linux-gnu`), GNU ld 2.42, GNU Make 4.3,
xorriso 1.5.6 and QEMU 8.2.2. These are observed versions, not exact version
requirements or a guarantee of byte-for-byte reproducible output.
The bundled Limine host utility requires an x86_64 Linux host with its dynamic
runtime. NASM and GDB are useful development tools but are not required by the
current C-only build.

On Linux Mint/Ubuntu, a human may install dependencies with:

```sh
sudo apt update
sudo apt install build-essential binutils xorriso qemu-system-x86
```

These commands are instructions only; Day 13 recovery does not install packages.
Do not download or upgrade Limine: the required 12.3.3 assets and their license
are included under [tools/limine](../tools/limine/README.md).

The ignored local `tools/downloads/limine-src/` checkout is associated with
12.4.0 (its ChangeLog), not the shipped 12.3.3 binaries. It is not compiled or
required. See the [provenance limitations](../tools/limine/README.md).

## Check the checkout

From the repository root:

```sh
git status --short --branch
(cd tools/limine && sha256sum -c SHA256SUMS)
gcc --version
ld --version
make --version
xorriso -version
qemu-system-x86_64 --version
```

Neither `tools/downloads/` nor existing `build/` or `iso_root/` contents are
required. The two Limine CD `.bin` files must be present in a clean checkout.

## Build and run

```sh
make
make iso
make run
```

`make` builds only `build/kernel.elf`. `make iso` stages the boot files, creates
`build/nucleos.iso`, then applies `limine bios-install` to that ISO file.
`make run` rebuilds the ISO and starts QEMU with E9 logging in `build/e9.log`.
Only test in QEMU; never install this OS or write the ISO to a real device.

For a full build with separate output, choose a previously unused directory:

```sh
make -B iso BUILD_DIR=build/day13-recovery ISO_ROOT=build/day13-recovery/iso_root
readelf -h -l build/day13-recovery/kernel.elf
qemu-system-x86_64 -cdrom build/day13-recovery/nucleos.iso -boot d \
  -no-reboot -no-shutdown -debugcon file:build/day13-recovery/e9.log \
  -global isa-debugcon.iobase=0xe9
```

The explicit QEMU command above boots an already generated ISO; unlike
`make run`, it does not regenerate it. It adds `-boot d` to select CD boot and
`-no-reboot -no-shutdown` to keep failures observable. Those flags are absent
from `make run`, which uses QEMU defaults. Both commands enable E9 at port
`0xe9`, but their log paths depend on the chosen build directory. The headless
audit additionally uses `-display none` and an external `timeout 15s`; those are
test controls, not Makefile behavior. A timeout exit code 124 must be assessed
alongside the E9 trace, not interpreted as successful boot by itself.

The ELF must be an x86_64 executable with a higher-half entry and loadable
text, read-only data and writable data segments. In the QEMU window confirm
`WELCOME TO NUCLEOS`. Expected E9 trace:

```text
[KERNEL_MAIN_ENTERED]
[FRAMEBUFFER_RESPONSE_OK]
[FRAMEBUFFER_COUNT_OK]
[FRAMEBUFFER_POINTER_OK]
[TERMINAL_INIT_DONE]
[TERMINAL_WRITE_DONE]
[HALT]
```

E9 success does not prove pixels are visible. The current renderer requires a
32-bpp framebuffer. The default QEMU command tests BIOS boot; UEFI boot remains
a separate test requiring appropriate firmware.

## Clean-checkout evidence

A build in a new output directory still reads the original checkout. To test
independence from ignored files, use a separate source tree containing only
tracked files plus the explicitly reviewed new Day 13 files. Do not copy ignored
`build/`, `iso_root/` or `tools/downloads/`. Until changes are committed, this is
a candidate-source test, not a test of a newly cloned Git commit. After a future
approved commit, repeat these checks from a clean checkout of that commit.
