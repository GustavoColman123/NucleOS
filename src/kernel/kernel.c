#include "kernel.h"
#include "terminal.h"

static void debug_putc(char c)
{
    __asm__ volatile ("outb %0, $0xe9" : : "a"(c));
}

static void debug_write(const char *text)
{
    while (*text)
    {
        debug_putc(*text);
        text++;
    }
}

static void halt_forever(void)
{
    debug_write("[HALT]\n");

    while (1)
    {
        __asm__ volatile ("hlt");
    }
}

void kernel_main(void)
{
    debug_write("[KERNEL_MAIN_ENTERED]\n");

    terminal_init();
    debug_write("[TERMINAL_INIT_DONE]\n");

    terminal_write("WELCOME TO NUCLEOS");
    debug_write("[TERMINAL_WRITE_DONE]\n");

    halt_forever();
}
