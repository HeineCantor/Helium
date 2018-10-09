#include "../include/vga_graphics.h"
#include "../include/tipi.h"

int main()
{
	const string LABEL_TITLE = "[Helium OS V0.1]";
	
	clear_screen(get_vga_color(VGA_CYAN, VGA_WHITE));
	println(LABEL_TITLE, get_vga_offset((VGA3_WIDTH - str_len(LABEL_TITLE))/2, 0));
	println("\nCiao! Benvenuto in Helium V0.1! Per adesso quello che siamo riusciti a fare e': una libreria driver video VGA 3, con scrittura e varie funzionalita'!");
	
	print("\nInserisci un comando: ");
	return 0;
}
