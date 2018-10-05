#ifndef VGA_GRAPHICS
#define VGA_GRAPHICS

#include "tipi.h"
#include "io_iasm.h"
#include "str_util.h"

#define VIDEO_ADDRESS 0xb8000

#define VGA3_WIDTH	80
#define	VGA3_HEIGHT	25

#define PORT_CURSOR_CTRL	0x3d4
#define PORT_CURSOR_DATA	0x3d5

typedef u8 vga_entry_color;

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

inline vga_entry_color get_vga_color(u8 back_color, u8 fore_color)
{
	return (back_color << 4) | fore_color;
}
inline u16 get_vga_offset(int x, int y)
{
	return x + y*VGA3_WIDTH;
}
inline char get_halfbyte_char(u8 num)
{
	num = num & 0x0f;
	return num < 10 ? num+48 : num + 55;
}

void new_line();
void put_char(const char c, int x, int y, vga_entry_color);
void put_char(const char c, u16 offset);
void put_char(const char c, u16 offset, vga_entry_color color);
void put_char(const char c, int x, int y, vga_entry_color color);
void print_string(string, int x, int y, vga_entry_color);
void print_string(string str, int x, int y);
void print_hex(u8 num, int x, int y);
void print_hex(u16 num, int x, int y);
void print_hex(u32 num, int x, int y);
void print_bits(u16 val, u16 offset);
void println_string(string str, int x, int y, vga_entry_color color);
void println_string(string str, int x, int y);
void clear_screen(vga_entry_color);
void get_cursor(int &x, int &y);
void get_cursor(u16 &offset);
u16 get_cursor();
void set_cursor(int x, int y);
void set_cursor(u16 offset);

#endif
