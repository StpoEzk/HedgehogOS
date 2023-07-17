#ifndef _IO_H
#define _IO_H 1

#include <stdint.h>

void outb(uint8_t value, uint16_t port);

uint8_t inb(uint16_t port);

void io_wait(void);

#endif
