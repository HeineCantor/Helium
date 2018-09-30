#include <stdint.h>

#define VIDEO_WIDTH 	80
#define VIDEO_HEIGHT 	25

#define VIDEO_MEMORY	0xb8000

enum VGA_COLOR
{
	VGA_BLACK 			= 0x00,
	VGA_BLUE			= 0x01,
	VGA_GREEN			= 0x02,
	VGA_CYAN			= 0x03,
	VGA_RED				= 0x04,
	VGA_MAGENTA 		= 0x05,
	VGA_BROWN			= 0x06,
	VGA_LIGHT_GREY		= 0x07,
	VGA_DARK_GREY		= 0x08,
	VGA_LIGHT_BLUE		= 0x09,
	VGA_LIGHT_GREEN		= 0x0a,
	VGA_LIGHT_CYAN		= 0x0b,
	VGA_LIGHT_RED		= 0x0c,
	VGA_LIGHT_MAGENTA	= 0x0d,
	VGA_LIGHT_BROWN		= 0x0e,
	VGA_WHITE 			= 0x0f
};

uint16_t get_vga_entry(uint8_t character, uint8_t color);
uint8_t get_color(uint8_t back_color, uint8_t font_color);
void print_char(const char c, int x, int y,const uint8_t color);
void print_char(const uint8_t c, uint8_t color);
void print_string(char* str, int x, int y, int str_len, uint8_t color);
void clear_screen(uint8_t color);
