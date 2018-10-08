#include "vga_graphics.h"

void new_line()
{
	int x, y;
	
	get_cursor(x, y);
	
	set_cursor(0, y+1);
}

void put_char(const char c, int x, int y, vga_entry_color color)
{
	put_char(c, (y * VGA3_WIDTH) + x, color);
}

void put_char(const char c, u16 offset, vga_entry_color color)
{
	u16* video_base = (u16*) VIDEO_ADDRESS;
	
	if(color) // if (color != 0)
	{
		video_base[offset] = (color << 8) | c;
	}
	else
	{
		video_base[offset] &= 0xff00;
		video_base[offset] |= c;
	}
	
	set_cursor(offset+1);
}

void print(string str, u16 offset, vga_entry_color color)
{
	int len = str_len(str);
	
	for(int i = 0; i < len; i++)
	{
		switch(str[i])
		{
			case '\n':
				new_line();
				offset = get_cursor();
				break;
			default:
				put_char(str[i], offset++, color);
		}
	}
}

void print(string str, u16 offset)
{
	print(str, offset, 0);
}

void print(string str)
{
	print(str, get_cursor(), 0);
}

void println(string str, u16 offset, vga_entry_color color)
{
	print(str, offset, 0);
	new_line();
}

void println(string str, u16 offset)
{
	println(str, offset, 0);
}

void println(string str)
{
	println(str, get_cursor(), 0);
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
	u16 offset = get_cursor();
	
	x = offset % VGA3_WIDTH;
	y = (offset - x) / VGA3_WIDTH;
}

u16 get_cursor()
{
	u16 offset = 0;
	
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
	set_cursor(get_vga_offset(x,y));
}

void set_cursor(u16 offset)
{
	//la porta data conterrà gli 8 bit bassi dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xf);
	port_byte_out(PORT_CURSOR_DATA, (u8) (offset & 0x00ff));
	//la porta data conterrà gli 8 bit alti dell'offset
	port_byte_out(PORT_CURSOR_CTRL, 0xe);
	port_byte_out(PORT_CURSOR_DATA, (u8) (offset >> 8));
}

void print_hex(u8 num, int x, int y)
{	
	u16 offset = get_vga_offset(x,y);
	put_char('0', offset++, 0);
	put_char('x', offset++, 0);
	put_char(get_halfbyte_char(num >> 4), offset++, 0);
	put_char(get_halfbyte_char(num), offset, 0);
}
void print_hex(u16 num, int x, int y)
{
	u16 offset = get_vga_offset(x,y);
	put_char('0', offset++, 0);
	put_char('x', offset++, 0);
	
	for (int i = 16 - 4; i >= 0; i-=4)
		put_char(get_halfbyte_char(num >> i), offset++, 0);
}
void print_hex(u32 num, int x, int y)
{
	u16 offset = get_vga_offset(x,y);
	put_char('0', offset++, 0);
	put_char('x', offset++, 0);
	
	for (int i = 32 - 4; i >= 0; i-=4)
		put_char(get_halfbyte_char(num >> i), offset++, 0);
}

void print_bits(u16 val, u16 offset)
{
	for (int i = 15; i >= 0; i--)
	{
		char c = ((val >> i) & 1) ? '1' : '0';
		put_char(c,offset++,0);
	}
}
