#include <sys/io.h>

void io_wait(void){
	outb (0x80, 0);
}

