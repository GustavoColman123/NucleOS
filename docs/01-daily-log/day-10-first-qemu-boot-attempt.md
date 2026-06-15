# NucleOS — Day 10: First QEMU Boot Attempt

## Date

June 14, 2026

## Goal

Run the first NucleOS bootable ISO candidate in QEMU.

The goal of this session is to test whether the ISO created in Day 9 can start inside a virtual machine.

## Main Idea

Day 9 created:

build/nucleos.iso

Day 10 tests that ISO in QEMU.

The expected flow is:

QEMU
↓
nucleos.iso
↓
Limine
↓
kernel.elf
↓
NucleOS kernel

## Safety Rule

The ISO is only tested inside QEMU.

The ISO is not written to a real disk.

The real laptop boot system is not modified.

## Possible Results

### Result 1

QEMU boots and shows Limine.

This means the ISO and bootloader are working.

### Result 2

Limine loads the kernel, but the kernel shows nothing.

This may be expected because the current kernel does not print text yet.

### Result 3

QEMU or Limine reports an error.

This is also useful because the error tells us what to fix.

## Today's Result

Pending.

## Reflection

The first boot attempt is an important milestone.

Even if it fails, the failure will provide technical information for the next step.

## Boot Test Result

The command was executed:

make run

Result:

QEMU opened successfully.

The NucleOS ISO booted into Limine.

Limine appeared on screen:

Limine 12.3.3 (x86-64, BIOS)

This is the first visible bootloader milestone of NucleOS.

The bootloader is alive.

The ISO is being recognized by QEMU.

The system reached Limine successfully.

However, Limine reported:

[config file contains no valid entries]

This means the ISO boots, but the Limine configuration still needs to be fixed before the kernel can be loaded.

## Celebration Note

This is an important milestone for NucleOS.

For the first time, the project produced an ISO that QEMU can boot into a real bootloader screen.

NucleOS has crossed from static build artifacts into an actual boot environment.

The next task is not to start over.

The next task is to fix the boot entry and make Limine load kernel.elf.

## Technical Status

Successful:

- build/nucleos.iso was generated.
- Limine BIOS stages were installed.
- QEMU launched the ISO.
- Limine appeared on screen.

Needs fixing:

- limine.conf does not currently define a valid boot entry.
- kernel.elf has not been visibly loaded yet.

## Next Step

Fix the Limine configuration file and run QEMU again.

## Boot Test Result

The command was executed:

make run

Result:

QEMU opened successfully.

The NucleOS ISO booted into Limine.

Limine appeared on screen:

Limine 12.3.3 (x86-64, BIOS)

This is the first visible bootloader milestone of NucleOS.

The bootloader is alive.

The ISO is being recognized by QEMU.

The system reached Limine successfully.

However, Limine reported:

[config file contains no valid entries]

This means the ISO boots, but the Limine configuration still needs to be fixed before the kernel can be loaded.

## Celebration Note

This is an important milestone for NucleOS.

For the first time, the project produced an ISO that QEMU can boot into a real bootloader screen.

NucleOS has crossed from static build artifacts into an actual boot environment.

The next task is not to start over.

The next task is to fix the boot entry and make Limine load kernel.elf.

## Technical Status

Successful:

- build/nucleos.iso was generated.
- Limine BIOS stages were installed.
- QEMU launched the ISO.
- Limine appeared on screen.

Needs fixing:

- limine.conf does not currently define a valid boot entry.
- kernel.elf has not been visibly loaded yet.

## Next Step

Fix the Limine configuration file and run QEMU again.

## Configuration Fix Result

After updating `boot/limine.conf`, Limine recognized the NucleOS boot entry.

The menu now shows:

NucleOS

This means the Limine configuration is now being parsed correctly.

This is a major improvement over the previous state, where Limine displayed:

[config file contains no valid entries]

## Updated Technical Status

Successful:

- QEMU launches the ISO.
- Limine starts successfully.
- Limine reads the configuration file.
- The NucleOS boot entry appears in the Limine menu.

Still pending:

- Confirm whether Limine can successfully load `boot/kernel.elf`.
- Confirm what happens after selecting the NucleOS entry.
- Add visible kernel output in a future step.

## Milestone Note

This is the first time NucleOS appears as a selectable boot entry inside Limine.

NucleOS is now visible inside a real bootloader menu.

## Kernel Load Attempt Result

After selecting the NucleOS entry, Limine attempted to load the kernel:

boot:///boot/kernel.elf

Limine reported:

Failed to open executable with path 'boot:///boot/kernel.elf'

This is progress compared to the previous configuration error.

The bootloader is now reading the NucleOS entry and attempting to load the kernel.

The current issue is likely related to the kernel path inside the Limine configuration or ISO layout.

## Updated Technical Status

Successful:

- QEMU boots the ISO.
- Limine starts.
- The NucleOS entry appears.
- Limine attempts to load the kernel.

Needs fixing:

- Limine cannot currently open the kernel path.
- The kernel path or ISO file location must be corrected.

## Kernel ELF Load Progress

After changing the kernel path to:

boot():/boot/kernel.elf

Limine successfully found the kernel ELF file.

Limine reported:

Loading executable 'boot():/boot/kernel.elf'...

This confirms that the kernel path is now correct.

However, Limine then reported:

PANIC: elf: Lower half PHDRs are not allowed

This means the kernel ELF file is currently linked into the lower half of memory.

The next fix is to update the linker script so the kernel is linked as a higher-half kernel.

## Higher-Half Kernel Fix Result

After updating the linker script for a higher-half kernel and rebuilding the ISO, the previous Limine error disappeared.

Previous error:

PANIC: elf: Lower half PHDRs are not allowed

After the fix, selecting the NucleOS entry no longer shows that Limine panic.

Result:

QEMU enters a black screen after selecting NucleOS.

This is likely expected at this stage because the current kernel does not have a text output system yet.

The current kernel only enters an infinite loop inside `kernel_main`.

## Final Day 10 Technical Status

Successful:

- QEMU boots the ISO.
- Limine starts.
- Limine reads the NucleOS entry.
- Limine finds `boot/kernel.elf`.
- The lower-half ELF issue was fixed.
- The boot process now reaches a black screen after selecting NucleOS.

Interpretation:

The kernel is likely being loaded and entered, but it has no visible output yet.

## Day 10 Milestone

NucleOS reached its first real boot attempt through QEMU and Limine.

The next major milestone is visible kernel output.

## Next Step

Implement a minimal text output mechanism so the kernel can display:

Welcome to NucleOS
