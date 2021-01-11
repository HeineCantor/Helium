#ifndef	IDT_H
#define IDT_H

#define IDT_GATE_NUMBER	256

#include "../include/tipi.h"
#include "../include/io_iasm.h"
//Interrupt Descriptor Table

// Descrittore del gate
typedef struct{
	u16 offset_lowerbits; // sono i 16 bit bassi di indirizzo della funzione handler
	u16 selector;	// selettore di segmento
	u8 zero;		// devono essere tutti 0
	u8 type_attr;		// tipi e attributi del descrittore
	u16 offset_higherbits;// sono i 16 bit alti di indirizzo della funzione handler
} __attribute__((packed)) IDT_entry;

// IDTR
/*
typedef struct{
	u16 limit;		// la lunghezza dell'idt - 1
	u32 base;		// indirizzo di contenimento della idt
	
} __attribute__((packed)) idt_register;
*/

enum GATE_TYPE{
	TASK_GATE_32_BIT			= 0x5,
	INTERRUPT_GATE_16_BIT		= 0x6,
	TRAP_GATE_16_BIT			= 0x7,
	INTERRUPT_GATE_32_BIT		= 0xE,
	TRAP_GATE_32_BIT			= 0xF
};

extern "C" int load_idt(long unsigned *);
extern "C" int irq0();
extern "C" int irq1();
extern "C" int irq2();
extern "C" int irq3();
extern "C" int irq4();
extern "C" int irq5();
extern "C" int irq6();
extern "C" int irq7();
extern "C" int irq8();
extern "C" int irq9();
extern "C" int irq10();
extern "C" int irq11();
extern "C" int irq12();
extern "C" int irq13();
extern "C" int irq14();
extern "C" int irq15();

void idt_init(void);
#endif
