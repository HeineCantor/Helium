#include "str_util.h"

unsigned int str_len(string str)
{
	register unsigned int i = 0;
	while(str[i++]) ;
	
	//-1 perché c'è il post-incremento che sfancula tutto
	return i-1;
}

bool is_numeric(string s)
{
	register unsigned int i = 0;
	char c;
	
	while(c = s[i])
		if (c < 48 || c > 57)
			return false;
	
	return true;
}