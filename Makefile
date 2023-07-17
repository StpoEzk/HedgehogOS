include make.config

LDFLAGS= -n -nostdlib -lgcc

all: headers build_kernel build_libc link build_iso

headers:
	cp -r $(DIR)/kernel/include/*.h $(BUILD_DIR)/sysroot/usr/include/kernel/
	cp -r $(DIR)/kernel/sys/include/*.h $(BUILD_DIR)/sysroot/usr/include/sys/
	cp -r $(DIR)/libc/include/*.h $(BUILD_DIR)/sysroot/usr/include/

build_kernel:
	cd kernel/ && make all

build_libc:
	cd libc/ && make all

link:
	$(CC) -T $(DIR)/kernel/arch/x86/linker.ld -o $(BUILD_DIR)/iso/kernel.bin $(BUILD_DIR)/*.o $(LDFLAGS)

build_iso:
	grub-mkrescue -o $(BUILD_DIR)/hgh.iso $(BUILD_DIR)/iso

