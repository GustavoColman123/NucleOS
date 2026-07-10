#ifndef NUCLEOS_TERMINAL_H
#define NUCLEOS_TERMINAL_H

#include <stdint.h>
#include <stddef.h>
#include "limine.h"

void terminal_init(struct limine_framebuffer *framebuffer);
void terminal_write(const char *text);

#endif
