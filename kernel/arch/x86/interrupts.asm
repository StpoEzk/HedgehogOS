extern isr_default
extern isr_clock
extern isr9_handler
extern IDT

%macro PUSHALL 0
    push rax
    push rcx
    push rdx
    push r8
    push r9
    push r10
    push r11
%endmacro

%macro POPALL 0
	pop r11
    pop r10
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rax
%endmacro

idt_descriptor:
    dw 4095
    dq IDT

load_idt:
	lidt[idt_descriptor]
	sti
	ret
	GLOBAL load_idt

; isr_def is called if no interrupt is defined
isr_def:
    PUSHALL
    call isr_default
    POPALL
    iretq
    GLOBAL isr_def


isr8:
	PUSHALL
	call isr_clock
	POPALL
	iretq
	GLOBAL isr8

isr9:
	PUSHALL
	call isr9_handler
	POPALL
	iretq
	GLOBAL isr9

