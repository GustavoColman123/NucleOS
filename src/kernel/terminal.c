#include "terminal.h"

static struct limine_framebuffer *fb = 0;

static size_t cursor_x = 40;
static size_t cursor_y = 40;

static const uint32_t COLOR_BACKGROUND = 0x00000000;
static const uint32_t COLOR_FOREGROUND = 0x00FFFFFF;

static void put_pixel(size_t x, size_t y, uint32_t color)
{
    if (fb == 0)
    {
        return;
    }

    if (x >= fb->width || y >= fb->height)
    {
        return;
    }

    if (fb->bpp != 32)
    {
        return;
    }

    uint8_t *base = (uint8_t *)fb->address;
    uint32_t *pixel = (uint32_t *)(base + y * fb->pitch + x * 4);

    *pixel = color;
}

static const uint8_t *get_glyph(char c)
{
    static const uint8_t SPACE[8] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };

    static const uint8_t A[8] = {
        0x18, 0x24, 0x42, 0x7E,
        0x42, 0x42, 0x42, 0x00
    };

    static const uint8_t C[8] = {
        0x3C, 0x42, 0x40, 0x40,
        0x40, 0x42, 0x3C, 0x00
    };

    static const uint8_t E[8] = {
        0x7E, 0x40, 0x40, 0x7C,
        0x40, 0x40, 0x7E, 0x00
    };

    static const uint8_t L[8] = {
        0x40, 0x40, 0x40, 0x40,
        0x40, 0x40, 0x7E, 0x00
    };

    static const uint8_t M[8] = {
        0x42, 0x66, 0x5A, 0x5A,
        0x42, 0x42, 0x42, 0x00
    };

    static const uint8_t N[8] = {
        0x42, 0x62, 0x52, 0x4A,
        0x46, 0x42, 0x42, 0x00
    };

    static const uint8_t O[8] = {
        0x3C, 0x42, 0x42, 0x42,
        0x42, 0x42, 0x3C, 0x00
    };

    static const uint8_t S[8] = {
        0x3E, 0x40, 0x40, 0x3C,
        0x02, 0x02, 0x7C, 0x00
    };

    static const uint8_t T[8] = {
        0x7E, 0x18, 0x18, 0x18,
        0x18, 0x18, 0x18, 0x00
    };

    static const uint8_t U[8] = {
        0x42, 0x42, 0x42, 0x42,
        0x42, 0x42, 0x3C, 0x00
    };

    static const uint8_t W[8] = {
        0x42, 0x42, 0x42, 0x5A,
        0x5A, 0x66, 0x42, 0x00
    };

    switch (c)
    {
        case 'A': return A;
        case 'C': return C;
        case 'E': return E;
        case 'L': return L;
        case 'M': return M;
        case 'N': return N;
        case 'O': return O;
        case 'S': return S;
        case 'T': return T;
        case 'U': return U;
        case 'W': return W;
        case ' ': return SPACE;
        default:  return SPACE;
    }
}

static void draw_char(char c)
{
    const uint8_t *glyph = get_glyph(c);
    const size_t scale = 4;

    for (size_t row = 0; row < 8; row++)
    {
        for (size_t col = 0; col < 8; col++)
        {
            uint8_t bit = glyph[row] & (1 << (7 - col));
            uint32_t color = bit ? COLOR_FOREGROUND : COLOR_BACKGROUND;

            for (size_t sy = 0; sy < scale; sy++)
            {
                for (size_t sx = 0; sx < scale; sx++)
                {
                    put_pixel(
                        cursor_x + col * scale + sx,
                        cursor_y + row * scale + sy,
                        color
                    );
                }
            }
        }
    }

    cursor_x += 9 * scale;
}

void terminal_init(struct limine_framebuffer *framebuffer)
{
    fb = framebuffer;
    cursor_x = 40;
    cursor_y = 40;

    if (fb == 0)
    {
        return;
    }

    if (fb->bpp != 32)
    {
        return;
    }

    for (size_t y = 0; y < fb->height; y++)
    {
        for (size_t x = 0; x < fb->width; x++)
        {
            put_pixel(x, y, COLOR_BACKGROUND);
        }
    }
}

void terminal_write(const char *text)
{
    while (*text)
    {
        char c = *text;

        if (c >= 'a' && c <= 'z')
        {
            c = (char)(c - 32);
        }

        draw_char(c);
        text++;
    }
}
