#include "vga_graphics.h"
#include "tipi.h"

unsigned char itoa(unsigned int num)
{
	return (num + 48);
}

void printbits(u16 val)
{
	for (int i = 0; i < 16; i++)
	{
		char c = ((val >> i) & 1) ? '1' : '0';
		put_char(c,15-i,0);
	}
}

int main()
{
	int x, y = 0;
	
	clear_screen(get_vga_color(VGA_CYAN, VGA_WHITE));
	print_string("[Helium OS]", VGA3_WIDTH / 2 - 5, 0, 0);
	print_string("Il sistema operativo si e' avviato correttamente!", 0, 2, 0);
	print_string("Se vedi questo messaggio sono riuscito a caricare tutto, e anche alla grande!", 0, 3, 0);
	print_string("Ad ogni modo tutte queste stringhe di testo occupano un MACELLO di spazio.", 0, 4, 0);
	print_string("Cosa c'e' da fare ora?", 0, 6, 0);
	print_string("   - sistemare la gestione del cursore, che va a cazzi suoi;", 0, 8, 0);
	print_string("   - creare una shell funzionante, questa e' pezzottissima.", 0, 9, 0);
	
	return 0;
}
