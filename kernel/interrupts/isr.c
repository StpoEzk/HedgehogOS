#include <stdint.h>
#include <stdlib.h>
#include <sys/io.h>
#include <kernel/tty.h>
#include "../drivers/keyboard/ps2/scan_codes_set1.h"
#include "idt.h"

void isr9_handler(void){
	uint8_t status = inb(KEYBOARD_STATUS_PORT);
	if(status & 0x01){
		uint8_t keycode = inb(KEYBOARD_DATA_PORT);
		if(keycode < 0x82){
        	tty_put_char(scan_codes_set1[keycode]);
		}
	}
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

void isr_clock(void){
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

void isr_default(void){
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

