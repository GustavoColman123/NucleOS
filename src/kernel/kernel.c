#include "kernel.h"
#include "terminal.h"
#include "limine.h"

__attribute__((used, section(".limine_requests_start_marker")))
static volatile uint64_t limine_requests_start_marker[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0,
    .response = 0
};

__attribute__((used, section(".limine_requests_end_marker")))
static volatile uint64_t limine_requests_end_marker[] = LIMINE_REQUESTS_END_MARKER;

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

    if (framebuffer_request.response == 0)
    {
        debug_write("[NO_FRAMEBUFFER_RESPONSE]\n");
        halt_forever();
    }

    debug_write("[FRAMEBUFFER_RESPONSE_OK]\n");

    if (framebuffer_request.response->framebuffer_count < 1)
    {
        debug_write("[NO_FRAMEBUFFERS]\n");
        halt_forever();
    }

    debug_write("[FRAMEBUFFER_COUNT_OK]\n");

    struct limine_framebuffer *framebuffer =
        framebuffer_request.response->framebuffers[0];

    if (framebuffer == 0)
    {
        debug_write("[FRAMEBUFFER_NULL]\n");
        halt_forever();
    }

    debug_write("[FRAMEBUFFER_POINTER_OK]\n");

    terminal_init(framebuffer);
    debug_write("[TERMINAL_INIT_DONE]\n");

    terminal_write("WELCOME TO NUCLEOS");
    debug_write("[TERMINAL_WRITE_DONE]\n");

    halt_forever();
}
