#include <stdint.h>
#include "io_iasm.h"
#include "str_util.h"

#define VIDEO_ADDRESS 0xb8000

#define VGA3_WIDTH	80
#define	VGA3_HEIGHT	25

#define PORT_CURSOR_CTRL	0x3d4
#define PORT_CURSOR_DATA	0x3d5

typedef uint8_t vga_entry_color;

const uint16_t* video_base = (uint16_t*) VIDEO_ADDRESS;

enum VGA_COLOR
{
	//colori scuri
	VGA_BLACK			= 0x0,
	VGA_BLUE			= 0x1,
	VGA_GREEN			= 0x2,
	VGA_CYAN			= 0x3,
	VGA_RED				= 0x4,
	VGA_MAGENTA			= 0x5,
	VGA_BROWN			= 0x6,
	VGA_LIGHT_GRAY		= 0x7,
	
	//colori chiari
	VGA_DARK_GRAY		= 0x8,
	VGA_LIGHT_BLUE		= 0x9,
	VGA_LIGHT_GREEN		= 0xa,
	VGA_LIGHT_CYAN		= 0xb,
	VGA_LIGHT_RED		= 0xc,
	VGA_LIGHT_MAGENTA	= 0xd,
	VGA_YELLOW			= 0xe,
	VGA_WHITE			= 0xf
};

uint8_t get_vga_color(uint8_t, uint8_t);
void print_char(const char c, int x, int y, vga_entry_color);
void print_char(const char c, int x, int y);
void print_string(string, int x, int y, vga_entry_color);
void print_string(string str, int x, int y);
void clear_screen(vga_entry_color);
void get_cursor(int &x, int &y);
void set_cursor(int x, int y);
