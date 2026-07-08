#ifndef NUCLEOS_LIMINE_H
#define NUCLEOS_LIMINE_H

#include <stdint.h>

#define LIMINE_REQUESTS_START_MARKER { \
    0xf6b8f4b39de7d1ae, \
    0xfab91a6940fcb9cf, \
    0x785c6ed015d3e316, \
    0x181e920a7852b9d9 \
}

#define LIMINE_REQUESTS_END_MARKER { \
    0xadc0e0531bb10d03, \
    0x9572709f31764c62 \
}

#define LIMINE_FRAMEBUFFER_REQUEST_ID { \
    0x9d5827dcd881dd75, \
    0xa3148604f6fab11b, \
    0x4f3f1e1d4cddc0ab, \
    0x8d1d26a08e3f13d4 \
}

struct limine_framebuffer {
    void *address;
    uint64_t width;
    uint64_t height;
    uint64_t pitch;
    uint16_t bpp;
    uint8_t memory_model;
    uint8_t red_mask_size;
    uint8_t red_mask_shift;
    uint8_t green_mask_size;
    uint8_t green_mask_shift;
    uint8_t blue_mask_size;
    uint8_t blue_mask_shift;
    uint8_t unused[7];
    uint64_t edid_size;
    void *edid;
};

struct limine_framebuffer_response {
    uint64_t revision;
    uint64_t framebuffer_count;
    struct limine_framebuffer **framebuffers;
};

struct limine_framebuffer_request {
    uint64_t id[4];
    uint64_t revision;
    struct limine_framebuffer_response *response;
};

#endif
