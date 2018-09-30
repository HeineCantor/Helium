#include "graphics.h"
#include <stdint.h>

int main()
{
	clear_screen(get_color(VGA_CYAN, VGA_WHITE));
	print_string("[Helium OS]", 35, 0, 11, 0);
	
	return 0;
}
