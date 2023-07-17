#include <sys/io.h>
#include <stdlib.h>
#include <stdint.h>
#include <kernel/tty.h>
#include "idt.h"

struct entry_idt {
	uint16_t offset_lowerbits;
	uint16_t selector;
	uint8_t ist;
	uint8_t type_attr;
	uint16_t offset_mid;
	uint32_t offset_higherbits;
	uint32_t zero;
};

struct entry_idt IDT[IDT_SIZE];

void remap_pic(){
	uint8_t a1, a2;

	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, 0);
	io_wait();
	outb(PIC2_DATA, 8);
	io_wait();
	outb(PIC1_DATA, 4);
	io_wait();
	outb(PIC2_DATA, 2);
	io_wait();

	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();

	outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

void load_idt_entry(){
	IDT[0].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[0].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[0].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[0].selector = 0x08;
	IDT[0].type_attr = 0x8e;
	IDT[0].zero = 0;
	IDT[0].ist = 0;

	IDT[1].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[1].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[1].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[1].selector = 0x08;
	IDT[1].type_attr = 0x8e;
	IDT[1].zero = 0;
	IDT[1].ist = 0;

	IDT[2].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[2].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[2].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[2].selector = 0x08;
	IDT[2].type_attr = 0x8e;
	IDT[2].zero = 0;
	IDT[2].ist = 0;

	IDT[3].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[3].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[3].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[3].selector = 0x08;
	IDT[3].type_attr = 0x8e;
	IDT[3].zero = 0;
	IDT[3].ist = 0;

	IDT[4].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[4].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[4].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[4].selector = 0x08;
	IDT[4].type_attr = 0x8e;
	IDT[4].zero = 0;
	IDT[4].ist = 0;

	IDT[5].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[5].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[5].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[5].selector = 0x08;
	IDT[5].type_attr = 0x8e;
	IDT[5].zero = 0;
	IDT[5].ist = 0;

    IDT[6].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
    IDT[6].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
    IDT[6].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[6].selector = 0x08;
	IDT[6].type_attr = 0x8e;
	IDT[6].zero = 0;
    IDT[6].ist = 0;

	IDT[7].offset_lowerbits = (uint16_t)(((uint64_t)&isr_def & 0x000000000000ffff));
	IDT[7].offset_mid = (uint16_t)(((uint64_t)&isr_def & 0x00000000ffff0000) >> 16);
	IDT[7].offset_higherbits = (uint16_t)(((uint64_t)&isr_def & 0xffffffff00000000) >> 32);
	IDT[7].selector = 0x08;
	IDT[7].type_attr = 0x8e;
	IDT[7].zero = 0;
	IDT[7].ist = 0;

	IDT[8].offset_lowerbits = (uint16_t)(((uint64_t)&isr8 & 0x000000000000ffff));
	IDT[8].offset_mid = (uint16_t)(((uint64_t)&isr8 & 0x00000000ffff0000) >> 16);
	IDT[8].offset_higherbits = (uint16_t)(((uint64_t)&isr8 & 0xffffffff00000000) >> 32);
	IDT[8].selector = 0x08; 
	IDT[8].type_attr = 0x8e;
	IDT[8].zero = 0;
	IDT[8].ist = 0;

	IDT[9].offset_lowerbits = (uint16_t)(((uint64_t)&isr9 & 0x000000000000ffff));
	IDT[9].offset_mid = (uint16_t)(((uint64_t)&isr9 & 0x00000000ffff0000) >> 16);
	IDT[9].offset_higherbits = (uint16_t)(((uint64_t)&isr9 & 0xffffffff00000000) >> 32);
	IDT[9].selector = 0x08;
	IDT[9].type_attr = 0x8e;
	IDT[9].zero = 0;
	IDT[9].ist = 0;
	remap_pic();
	outb(0x21, 0xfd);
	outb(0xa1, 0xff);
	load_idt();
}

