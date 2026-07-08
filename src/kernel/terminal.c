#include "terminal.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static volatile uint16_t *const VGA_MEMORY = (uint16_t *)0xB8000;

static size_t terminal_row = 0;
static size_t terminal_column = 0;

static uint8_t vga_entry_color(uint8_t foreground, uint8_t background)
{
    return foreground | (background << 4);
}

static uint16_t vga_entry(unsigned char character, uint8_t color)
{
    return (uint16_t)character | ((uint16_t)color << 8);
}

void terminal_init(void)
{
    terminal_row = 0;
    terminal_column = 0;

    uint8_t color = vga_entry_color(15, 0);

    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = y * VGA_WIDTH + x;
            VGA_MEMORY[index] = vga_entry(' ', color);
        }
    }
}

static void terminal_putchar(char character)
{
    uint8_t color = vga_entry_color(15, 0);

    if (character == '\n')
    {
        terminal_column = 0;
        terminal_row++;

        if (terminal_row >= VGA_HEIGHT)
        {
            terminal_row = 0;
        }

        return;
    }

    const size_t index = terminal_row * VGA_WIDTH + terminal_column;
    VGA_MEMORY[index] = vga_entry((unsigned char)character, color);

    terminal_column++;

    if (terminal_column >= VGA_WIDTH)
    {
        terminal_column = 0;
        terminal_row++;

        if (terminal_row >= VGA_HEIGHT)
        {
            terminal_row = 0;
        }
    }
}

void terminal_write(const char *text)
{
    while (*text)
    {
        terminal_putchar(*text);
        text++;
    }
}
