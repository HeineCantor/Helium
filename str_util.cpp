#include "str_util.h"

unsigned int str_len(string str)
{
	register unsigned int i = 0;
	while(str[i++]) ;
	
	return i;
}
