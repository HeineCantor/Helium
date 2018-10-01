#include "str_util.h"

int str_len(string str)
{
	char buffer;
	int counter = 0;
	
	do
	{
		buffer = *str++;
		counter++;
	}while(buffer != 0);
	
	return counter;
}
