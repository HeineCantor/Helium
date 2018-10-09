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
		if (c < '0' || c > '9')
			return false;
	
	return true;
}

void to_upper(char* s)
{
	register unsigned int i = 0;
	char c;
	
	while(c = s[i])
		if (c >= 'a' && c <= 'z')
			c -= 32;
		
}
void to_lower(char* s)
{
	register unsigned int i = 0;
	char c;
	
	while(c = s[i])
		if (c >= 'A' && c <= 'Z')
			c += 32;
		
}
