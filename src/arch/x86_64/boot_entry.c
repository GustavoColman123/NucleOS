#include "../../kernel/kernel.h"

void _start(void)
{
    /*
     * Architecture-specific entry point.
     *
     * The bootloader will eventually transfer control here.
     * This function then calls the generic kernel entry point.
     */

    kernel_main();

    /*
     * If kernel_main ever returns, stop the CPU.
     * This should not normally happen.
     */

    while (1)
    {
        __asm__ volatile ("hlt");
    }
}
