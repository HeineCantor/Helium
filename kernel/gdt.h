#ifndef _GDT_H_
#define _GDT_H_

#define GDT_ENTRIES 3

#include "../include/tipi.h"

typedef struct
{
    u16 limit_low;  //LIMIT (15 - 0)
    u16 base_low;   //BASE (15 - 0)
    u8 base_middle; //BASE (23 - 16)
    u8 type_flag;   //TYPE FLAG
    u8 granularity; //GRANULARITY E LIMIT(19 - 16)
    u8 base_high;   //BASE (31 - 24)
}__attribute__((packed)) gdt_entry;

typedef struct
{
    u16 limit;
    u32 base;
}__attribute__((packed)) gdt_pointer;

typedef struct tss_entry {
	u32	prev_tss;
	u32	esp0;
	u32	ss0;
	u32	esp1;
	u32	ss1;
	u32	esp2;
	u32	ss2;
	u32	cr3;
	u32	eip;
	u32	eflags;
	u32	eax;
	u32	ecx;
	u32	edx;
	u32	ebx;
	u32	esp;
	u32	ebp;
	u32	esi;
	u32	edi;
	u32	es;
	u32	cs;
	u32	ss;
	u32	ds;
	u32	fs;
	u32	gs;
	u32	ldt;
	u16	trap;
	u16	iomap_base;
} __attribute__ ((packed)) tss_entry;


void gdt_insert_entry(u8 id, u32 base, u32 limit, u8 type, u8 granularity);
void create_tss(u8 id, u16 ss0, u32 esp0);

void gdt_setup();

extern "C" void gdt_load();
extern "C" void tss_load();

#endif