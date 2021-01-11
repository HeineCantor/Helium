#include "../include/vga_graphics.h"
#include "../include/tipi.h"
#include "../idt/idt.h"
#include "../idt/timer.h"

#define DISK_ADDRESS 0x1337

bool disk_ready();
u32 disk_request_task();
void query_disk(u32 address);
u32 read_disk();

int main()
{
	idt_init();
    
	init_timer();
    enable_timer();

	disable_cursor();

	const string LABEL_TITLE = "[Helium OS V0.1]";
	
	clear_screen(get_vga_color(VGA_CYAN, VGA_WHITE));
	println(LABEL_TITLE, get_vga_offset((VGA3_WIDTH - str_len(LABEL_TITLE))/2, 0));
	println("\nCiao! Benvenuto in Helium V0.1!");

	disk_request_task();

	return 0;
}

void disk_request_task()
{
	query_disk(DISK_ADDRESS);

	while(!disk_ready()){}	//aspetta fin qunado il disco non è pronto

	disk_buffer_read =  read_disk();
}

void io_server_task()
{
	query_disk(DISK_ADDRESS);

	wait(sem_data_ready);

	disk_buffer_read = read_disk();
}

void io_server_task()
{
	if(disk_ready)
	{
		disk_request_task = read_disk();
	}
	else if(disk_request)
	{
		query_disk(DISK_ADDRESS);
	}
}

void query_disk(u32 address)
{
	//fai cose
}

u32 read_disk()
{
	return 0x12345678;
}

bool disk_ready()
{
	return false;
}