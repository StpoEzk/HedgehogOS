#include "multiboot2/multiboot2.h"

#include "../drivers/tty/vga.h"
#include "../include/tty.h"
#include "../interrupts/idt.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void kernel_main(uint32_t mbi_addr){
	tty_init();
	tty_clear();
	load_idt_entry();

	printf("\n****************** \n");
	printf("----HedgehogOS---- \n");
	printf("****************** \n\n");

	printf("Its DEV version %s... \n", "0.0.2");
	printf("Boot...");

	print_multiboot2_info(mbi_addr);

	tty_up_lines();
	tty_write_string("");
	tty_up_lines();

	//tests
	//char bff[512];
	//dtoa((double)1.888, bff, 2);
	//tty_write_string(bff);

	while(true){
		vga_put_char('0', 32, 0);
		vga_put_char('1', 32, 0);
		vga_put_char('2', 32, 0);
		vga_put_char('3', 32, 0);
		vga_put_char('4', 32, 0);
		vga_put_char('5', 32, 0);
	}
}

void print_multiboot2_info(uint32_t mbi_addr){
	struct multiboot_tag *tag;

	//unsigned size = *(unsigned *) mbi_addr;

	for(tag = (struct multiboot_tag *)(mbi_addr + 8);
		tag->type != MULTIBOOT_TAG_TYPE_END;
		tag = (struct multiboot_tag *) ((multiboot_uint8_t *) tag + ((tag->size + 7) & ~7)))
		{
		    if(mbi_addr & 7){
		    	printf("Unaligned mbi: 0x%x", mbi_addr);
		    	return;
		    }
		    switch (tag->type){
				case MULTIBOOT_TAG_TYPE_BASIC_MEMINFO:
					printf(
						"mem_lower = %dKB, mem_upper = %dMB \n", 
						((struct multiboot_tag_basic_meminfo *) tag)->mem_lower,
						((struct multiboot_tag_basic_meminfo *) tag)->mem_upper / 1000
					);
				break;

				case MULTIBOOT_TAG_TYPE_MMAP:
				{
					multiboot_memory_map_t *mmap;

            		for(mmap = ((struct multiboot_tag_mmap *) tag)->entries;
            			(multiboot_uint8_t *) mmap < (multiboot_uint8_t *) tag + tag->size;
            			mmap = (multiboot_memory_map_t *) ((unsigned long) mmap + ((struct multiboot_tag_mmap *) tag)->entry_size)
					){
              			printf(
							"base_addr = 0x%llx%llx,"
                      		" length = 0x%x%x, type = 0x%x\n",
                      		(int64_t) (mmap->addr >> 64),
                      		(int64_t) (mmap->addr & 0xffffffff),
                      		(int64_t) (mmap->len >> 64),
                      		(int64_t) (mmap->len & 0xffffffff),
                      		(int64_t) mmap->type
						);
					}
          	}
          break;
		}
	}
}
