#ifndef NUCLEOS_TERMINAL_H
#define NUCLEOS_TERMINAL_H

#include <stdint.h>
#include <stddef.h>

void terminal_init(void);
void terminal_write(const char *text);

#endif
