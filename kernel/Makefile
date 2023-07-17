include ../make.config
KERNEL_DIR := ${DIR}/kernel

CFLAGS := ${CFLAGS} -g -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -mcmodel=large -mno-avx -mno-red-zone --sysroot="$(BUILD_DIR)/sysroot" -isystem="/usr/include"

C_FILES := $(shell find $(KERNEL_DIR) -type f -name '*.c')

all: nasm kernel

kernel:
	$(CC) $(C_FILES) $(CFLAGS)
	mv ./*.o $(BUILD_DIR)

nasm:
	nasm -felf64 -o $(BUILD_DIR)/boot.o $(KERNEL_DIR)/arch/x86/boot.asm
	nasm -felf64 -o $(BUILD_DIR)/checks.o $(KERNEL_DIR)/arch/x86/checks.asm
	nasm -felf64 -o $(BUILD_DIR)/init_long_mode.o $(KERNEL_DIR)/arch/x86/init_long_mode.asm
	nasm -felf64 -o $(BUILD_DIR)/interrupts.o $(KERNEL_DIR)/arch/x86/interrupts.asm


