#ifndef	IDT_H
#define IDT_H

#define IDT_GATE_NUMBER	256

#include "../include/tipi.h"

// Descrittore del gate
typedef struct{
	u16 low_offset; // sono i 16 bit bassi di indirizzo della funzione handler
	u16 selector;	// selettore di segmento
	u8 zero;		// devono essere tutti 0
	u8 type;		// tipi e attributi del descrittore
	u16 high_offset;// sono i 16 bit alti di indirizzo della funzione handler
} __attribute__((packed)) idt_gate;

// IDTR
typedef struct{
	u16 limit;		// la lunghezza dell'idt - 1
	u32 base;		// indirizzo di contenimento delal idt
	
} __attribute__((packed)) idt_register;

idt_register idtr;
idt_gate idt[IDT_GATE_NUMBER];

void set_idtr();
void gate_handler(int n, u32 handler); //n = numero gate, handler = indirizzo funzione handler

#endif
