global long_mode_start

extern kernel_main

bits 64

clean_regs:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    ret

align   4
section .text
long_mode_start:
	call clean_regs
    mov qword [0xb8000], rax
    call kernel_main
	cli
    hlt
