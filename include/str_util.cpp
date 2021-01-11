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
	register char c;
	
	while(c = s[i++])
		if (c < '0' || c > '9')
			return false;
	
	return true;
}

char* to_upper(char* s)
{
	register unsigned int i = 0;
	while(s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		
		i++;
	}
	
	return s;	
}
char* to_lower(char* s)
{
	register unsigned int i = 0;
	while(s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		
		i++;
	}
	
	return s;
}
