#include <stdint.h>
#include <sys/io.h>

void outb(uint8_t value, uint16_t port){
	asm volatile(
		"outb {%0, %1 | %1, %0}"
		: :
		"a"(value),
		"Nd"(port)
	);
}
