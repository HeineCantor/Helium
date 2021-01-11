#ifndef _TIMER_H_
#define _TIMER_H_

#include "../include/tipi.h"

extern u32 internal_time_counter; //2^32 = un bel po' di tick di timer, ragionando con la frequenza standard del PIT (~ 1MHz) posso contare fino a un giorno di utilizzo del SO

void init_timer();
void enable_timer();
void disable_timer();

#endif