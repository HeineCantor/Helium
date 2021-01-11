#include "gdt.h"

gdt_entry gdt[GDT_ENTRIES + 1]; //+1 per la prima entry che deve essere piena di 0
gdt_pointer gdt_ptr;

tss_entry tss;

void gdt_insert_entry(u8 id, u32 base, u32 limit, u8 type, u8 granularity) 
{
	gdt[id].base_low    =	(base & 0xFFFF);
	gdt[id].base_middle =	(base >> 16) & 0xFF;
	gdt[id].base_high   =	(base >> 24) & 0xFF;
	
	gdt[id].limit_low   =	(limit & 0xFFFF);
	gdt[id].granularity =	(limit >> 16) & 0X0F;
	
	gdt[id].granularity |= (granularity & 0xF0);
	
	gdt[id].type_flag   = type;
} 

void create_tss(u8 id, u16 ss0, u32 esp0)
{
	u32 base = (u32)&tss;
	u32 limit = base + sizeof(tss_entry);

	gdt_insert_entry(id, base, limit, 0x89, 0x40);

	tss.ss0 = ss0;
	tss.esp0 = esp0;

	tss.cs = 0x0B;

	tss.ss = tss.ds  = tss.es = tss.fs = tss.gs = 0x13;

	tss.iomap_base = sizeof(tss_entry);
}

void gdt_setup()
{
    gdt_ptr.base = (u32)&gdt;
    gdt_ptr.limit = (sizeof(gdt_entry) * 4) - 1;

    gdt_insert_entry(0, 0, 0, 0, 0);
    gdt_insert_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_insert_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
	create_tss(3, 0x10, 0);

    gdt_load();
	tss_load();
}
