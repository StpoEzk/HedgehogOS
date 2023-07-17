#ifndef _IDT_H
#define _IDT_H 1

#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA 0xA1

#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e

void load_idt_entry();

// isr_def is called if no interrupt is defined
extern uint64_t isr_def;

extern uint64_t isr8;
extern uint64_t isr9;

extern void load_idt(void);

#endif
