include ../make.config
LIBC_DIR := ${DIR}/libc

CFLAGS := ${CFLAGS} -g -c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -mcmodel=large -mno-avx -mno-red-zone --sysroot="$(BUILD_DIR)/sysroot" -isystem="/usr/include" 

C_FILES := $(shell find $(LIBC_DIR) -type f -name '*.c')

all: libc

libc:
	$(CC) $(C_FILES) $(CFLAGS)
	mv ./*.o $(BUILD_DIR)
