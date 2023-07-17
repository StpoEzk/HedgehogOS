#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>

#include "vga.h"

static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

void vga_put_char(unsigned char c, int x, int y){
	volatile uint16_t* addr = (uint16_t *)(VGA_MEMORY + (y * 80 + x));
	uint8_t colors = ((DELAULT_COLOR_BACKGROUND << 4) | (DELAULT_COLOR_TEXT & 0x0F));
	*addr = c | (colors << 8);
}

