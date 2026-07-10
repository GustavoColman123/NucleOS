# Framebuffer

A framebuffer is a region of memory that represents pixels on the screen.

If the kernel writes pixel data into the framebuffer, the display changes.

## Why NucleOS Uses a Framebuffer

At this stage, traditional VGA text mode was not visible in the current QEMU/Limine boot environment.

The reliable solution was to request a framebuffer from Limine and draw pixels directly.

## Limine Framebuffer Request

The kernel asks Limine for a framebuffer using a framebuffer request.

If the request is recognized, Limine fills a response structure containing information such as:

- framebuffer address
- width
- height
- pitch
- bits per pixel

## Important Fields

### address

The memory address where pixels are stored.

### width

The number of horizontal pixels.

### height

The number of vertical pixels.

### pitch

The number of bytes per row.

Pitch is not always equal to:

width * bytes_per_pixel

### bpp

Bits per pixel.

NucleOS currently expects:

32 bpp

## NucleOS Usage

NucleOS receives the framebuffer from Limine and passes it to:

terminal_init(framebuffer)

Then the kernel draws characters by writing pixels directly into framebuffer memory.

## Day 12 Result

After correcting the Limine framebuffer request ID, NucleOS successfully displayed:

WELCOME TO NUCLEOS
