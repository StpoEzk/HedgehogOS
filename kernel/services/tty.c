#include <stddef.h>
#include <string.h>

#include "kernel/tty.h"
#include "../drivers/tty/vga.h"

enum TTY_TYPE {
	VGA_TEXT_MODE,
};

static enum TTY_TYPE tty_type;

static int wigth;
static int height;
static int last_x;
static int last_y;

static unsigned char frame_buffer[512][512] = {0, {0, "K"}};

void tty_init(void){
	tty_type = VGA_TEXT_MODE;
	wigth = VGA_WIDTH;
	height = VGA_HEIGHT;
	last_x = 0;
	last_y = height - 1;
}

static void put_char(unsigned char c, int x, int y){
    switch(tty_type){
        case VGA_TEXT_MODE:
            vga_put_char(c, x, y);
        break;
    }
}

void tty_put_char(unsigned char c){
	if(c == '\n'){
		tty_up_lines();
		return;
	}
	if(c == '\b'){
		tty_del_char();
		return;
	}
	put_char(c, last_x, last_y);
	frame_buffer[last_y][last_x] = c;

	last_x++;
	if(last_x >= wigth){
		last_x = 0;
		tty_up_lines();
	}
}

void del_char(int x, int y){
    put_char(' ', x, y);
}

void tty_del_char(){
	if(last_x > 0){
		del_char(last_x - 1, last_y);
		frame_buffer[last_y][last_x - 1] = ' ';
		last_x--;
		return;
	}
	del_char(last_x, last_y);
	frame_buffer[last_y][last_x] = ' ';
	//TODO
}


void tty_clear(){
	for(int y = height - 1; y >= 0; y--){
		for(int x = wigth - 1; x >= 0; x--){
			del_char(x, y);
		}
	}
}

static void up_frame_buffer(){
	for(int y = 1; y <= height - 1; y++){
        for(int x = 0; x <= wigth - 1; x++){
            frame_buffer[y - 1][x] = frame_buffer[y][x];
			frame_buffer[y][x] = ' ';
        }
    }
	put_char(frame_buffer[0][1], 8, 8);
}

static void update_frame(){
	for(int y = 0; y < 24; y++){
        for(int x = 0; x < 79; x++){
            put_char(frame_buffer[y][x], x, y);
        }
    }
}

void tty_up_lines(){
	up_frame_buffer();
	tty_clear();
	update_frame();
	last_x = 0;
}

void tty_write(const char* data, size_t size){
	for(size_t i = 0; i < size; i++){
		tty_put_char(data[i]);
	}
}

void tty_write_string(const char* data){
	tty_write(data, strlen(data));
}

//temp!!!!
void tty_write_int(int data){
	char buff[512];
	tty_write_string(itoa(data, buff, 10));
}

void tty_write_int_h(int data){
	char buff[512];
	tty_write_string(itoa(data, buff, 16));
}

void tty_write_uint64_h(uint64_t data){
    char buff[512];
    tty_write_string(ui64toa(data, buff, 16));
}
