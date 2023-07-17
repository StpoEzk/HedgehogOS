#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>

size_t strlen(const char*);

char* strncpy(char* dest, const char* src, size_t n);

void* memset(void * ptr, int value, size_t len);

#endif
