#include "timer.h"
#include "../include/io_iasm.h"

u32 internal_time_counter;

void init_timer()
{
    internal_time_counter = 0;
}

void enable_timer()
{
	//0xFE = 0b(1111 1110)
    port_byte_out(0x21 , 0xFE);
}

void disable_timer()
{
	u8 current_mask = port_byte_in(0x21);
	current_mask |= 1;

	port_byte_out(0x21 , current_mask);
}