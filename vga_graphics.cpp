#include "vga_graphics.h"

uint8_t get_color(uint8_t back_color, uint8_t font_color)
{
	uint8_t color = back_color << 4;
	color |= font_color;
	
	return color;
}

// per comporre i 16 bit per la definizione del carattere + il colore
uint16_t get_vga_entry(uint8_t character, uint8_t color)
{
	uint16_t entry = color << 8;
	entry |= character;
	
	return entry;
}

void print_char(const char c, int x, int y, uint8_t color)
{
	int offset = 0;
	uint16_t *ptr_memory = (uint16_t *) VIDEO_MEMORY;
	
	if((x >= 0 && y >= 0) && (x <= VIDEO_WIDTH && y <= VIDEO_HEIGHT))
	{
		offset = x + (VIDEO_WIDTH * y);
	}
	
	if(color != 0)
		ptr_memory[offset] = get_vga_entry(c, color);
	else
	{
		ptr_memory[offset] &= 0xff00;
		ptr_memory[offset] |= c;
	}
}

void print_char(const uint8_t c, uint8_t color)
{
	//dovrebbe inserire un carattere alla posizione del cursore
}

void print_string(char* string, int x, int y, int str_len, uint8_t color)
{
	for(int i = 0; i < str_len; i++)
	{
		print_char(string[i], x+i, y, color);
	}
}

void clear_screen(uint8_t back_color)
{
	for(int i = 0; i < VIDEO_WIDTH; i++)
	{
		for(int j = 0; j < VIDEO_HEIGHT; j++)
			print_char(' ', i, j, back_color);
	}
}
