#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>

void tty_init(void);
void tty_put_char(unsigned char c);
void tty_write(const char* data, size_t size);
void tty_write_string(const char* data);
void tty_write_int(int data);
void tty_write_int_h(int data);
void tty_write_uint64_h(uint64_t data);
void tty_clear();

#endif

