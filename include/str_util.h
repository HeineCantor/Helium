typedef const char* string;

unsigned int str_len(string str);
bool is_numeric(string s); // restituisce TRUE solo se la stringa è composta da soli numeri. Restituisce FALSE anche se contiene white-spaces, oppure se è espressa nel formato 0x1234