# Limine 12.3.3

NucleOS vendors the existing local Limine 12.3.3 asset set. No update or download
was performed during Day 13 recovery (2026-10-31).

The host utility reports `Limine 12.3.3`; the BIOS support image embeds the same
version. All five boot assets match the existing local
`tools/downloads/limine-binary/` copies by SHA-256. That directory is ignored and
is not needed to build. The original archive URL and authenticity have not been
independently verified. The upstream link below identifies the project only; it
is not evidence of the exact archive or tag used. Upstream project: https://github.com/limine-bootloader/limine

| File | Purpose |
| --- | --- |
| `limine` | Linux x86_64 host utility; applies BIOS installation to the generated ISO |
| `limine-bios.sys` | BIOS bootloader support |
| `limine-bios-cd.bin` | BIOS CD boot image |
| `limine-uefi-cd.bin` | UEFI CD boot image |
| `BOOTX64.EFI` | x86_64 UEFI loader |
| `BOOTIA32.EFI` | IA-32 UEFI loader |

[SHA256SUMS](SHA256SUMS) records all six assets. Verify from the repository root:

```sh
(cd tools/limine && sha256sum -c SHA256SUMS)
```

These assets are distributed under the accompanying [Limine license](LICENSE)
(BSD-2-Clause), separately from the project's MIT license. Binary redistribution
must reproduce the copyright notice, conditions and disclaimer in accompanying
materials. Keep this license with redistributed assets and include it with any
separately distributed ISO. The Makefile does not embed it in the ISO.

The current kernel uses a minimal local protocol header and no explicit base
revision tag. Preserve the verified asset set for Day 12 reproduction; a future
bootloader or protocol change requires its own compatibility review.

## Local source checkout is separate

The ignored `tools/downloads/limine-src/` checkout has HEAD `86571ed` and a
`ChangeLog` headed `Release 12.4.0`. This is the local source referred to as
12.4.0; HEAD has no exact tag in the local checkout. It is not demonstrated to
be the source used to build the vendored 12.3.3 binaries. Do not use this source
to establish 12.3.3 protocol compatibility or binary provenance.

The Makefile uses only the assets under `tools/limine/`; the ignored source is
not a build dependency. The host utility reports 12.3.3 and the local binary
package's `limine.c` defines that version, but the exact original archive URL,
release tag, download procedure and upstream authenticity remain unproven.
SHA-256 establishes local byte identity, not upstream authenticity.
