#include "vga_graphics.h"

void new_line()
{
	int x, y;
	
	get_cursor(x, y);
	
	set_cursor(0, y+1);
}

void put_char(const char c, int x, int y, vga_entry_color color)
{
	uint16_t* video_base = (uint16_t*) VIDEO_ADDRESS;
	int offset = (y * VGA3_WIDTH) + x;
	
	if(color) // if (color != 0)
	{
		video_base[offset] = (color << 8) | c;
	}
	else
	{
		video_base[offset] &= 0xff00;
		video_base[offset] |= c;
	}
	
	set_cursor(x+1, y);
}

void put_char(const char c, int x, int y)
{
	put_char(c, x, y, 0);
}

void print_string(string str, int x, int y, vga_entry_color color)
{
	int len = str_len(str);
	
	for(int i = 0; i < len; i++)
	{
		switch(str[i])
		{
			case '\n':
				new_line();
				break;
			default:
				put_char(str[i], x + i, y, color);
		}
	}
}

void print_string(string str, int x, int y)
{
	print_string(str, x, y, 0);
}

void println_string(string str, int x, int y, vga_entry_color color)
{
	print_string(str, x, y, 0);
	new_line();
}

void println_string(string str, int x, int y)
{
	println_string(str, x, y, 0);
}

void clear_screen(vga_entry_color color)
{
	for(int i = 0; i < VGA3_HEIGHT; i++)
	{
		for(int j = 0; j < VGA3_WIDTH; j++)
		{
			put_char(' ', j, i, color);
		}
	}
	
	set_cursor(0);
}

void get_cursor(int &x, int &y)
{
	uint16_t offset = get_cursor();
	
	x = offset % VGA3_WIDTH;
	y = (offset - x) / VGA3_WIDTH;
}

void get_cursor(uint16_t &offset)
{
	offset = get_cursor();
}

uint16_t get_cursor()
{
	uint16_t offset = 0;
	
	//la porta data conterrà gli 8 bit bassi dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xe);
	offset = port_byte_in(PORT_CURSOR_DATA);
	offset = offset << 8;
	//la porta data conterrà gli 8 bit alti dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xf);
	offset |= (port_byte_in(PORT_CURSOR_DATA));
	
	
	return offset;
}

void set_cursor(int x, int y)
{
	uint16_t offset = x + y * VGA3_WIDTH;
	set_cursor(offset);
}

void set_cursor(uint16_t offset)
{
	//la porta data conterrà gli 8 bit bassi dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xf);
	port_byte_out(PORT_CURSOR_DATA, (uint8_t) (offset & 0x00ff));
	//la porta data conterrà gli 8 bit alti dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xe);
	port_byte_out(PORT_CURSOR_DATA, (uint8_t) (offset >> 8));
}
