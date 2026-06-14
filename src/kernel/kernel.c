#include "kernel.h"

void kernel_main(void)
{
    /*
     * This is the main entry point for the generic NucleOS kernel.
     *
     * In the future, this function will initialize:
     *
     * - screen output
     * - memory management
     * - interrupts
     * - keyboard input
     * - kernel services
     *
     * For now, it only stays alive forever.
     */

    while (1)
    {
        /*
         * Infinite loop.
         *
         * A real kernel cannot simply return to a host operating system.
         * Once the kernel is running, it owns the machine.
         */
    }
}
