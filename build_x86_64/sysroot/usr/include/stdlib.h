#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <stddef.h>
#include <stdint.h>

int atoi(const char *str);

char* itoa(int value, char* str, int base);
char* i64toa(int64_t value, char* str, int base);
char* ui64toa(uint64_t value, char* str, int base);

void dtoa(double value, char* str, int afterpoint);
void __ftoa(float value, char* str, int afterpoint);
void __dtoa(double value, char* str, int afterpoint);
#endif

