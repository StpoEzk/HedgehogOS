#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define SYMBOLS "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"

char* itoa(int value, char* str, int base){
	if(base < 2 || base > 36){ 
		*str = '\0';
		return str;
	}

	int tmp_num;
	char* ptr = str, *ptr1 = str, tmp_char;

	do{
		tmp_num = value;
		value /= base;
		*ptr++ = SYMBOLS[35 + (tmp_num - value * base)];
	}while(value);

	if(tmp_num < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr){
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return str;
}

char* ui64toa(uint64_t value, char* str, int base){
	if(base < 2 || base > 36){
        *str = '\0';
        return str;
    }

	uint64_t tmp_num;
    char* ptr = str, *ptr1 = str, tmp_char;

	do{
		tmp_num = value;
        value /= base;
        *ptr++ = SYMBOLS[35 + (tmp_num - value * base)];
    }while(value);

    *ptr-- = '\0';
    while(ptr1 < ptr){
        tmp_char = *ptr;
		*ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
	return str;
}

char* i64toa(int64_t value, char* str, int base){
	if(base < 2 || base > 36){
		*str = '\0';
        return str;
    }

    int64_t tmp_num;
    char* ptr = str, *ptr1 = str, tmp_char;

    do{
        tmp_num = value;
        value /= base;
        *ptr++ = SYMBOLS[35 + (tmp_num - value * base)];
    }while(value);

    *ptr-- = '\0';
    while(ptr1 < ptr){
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return str;
}
