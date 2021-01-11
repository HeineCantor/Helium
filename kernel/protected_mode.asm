[bits 16]

; Predisposizione a passare alla protected mode
switch_to_pm:
	
	cli			; spegni qualsiasi tipo di interrupt fin quando non avremo
				; impostato il vettore di interrupt nella protected mode	
	
	lgdt [gdt_descriptor]

	mov eax, cr0			; prendo il registro di controllo c0
	or eax, 0x1				; imposto il primo bit a 1, per passare alla protected mode
	mov cr0, eax			; lo rimetto al suo posto

	jmp 0x08:init_pm	; ho fatto un far jump a un nuovo segmento
								; in questo modo il code segment è stato aggiornato a quello che gli ho specificato
								; e la pipeline è stata buttata via, poiché poteva contenere ancora istruzioni a 16 bit
	
[bits 32]

[extern gdt_ptr]

global gdt_load
global tss_load

gdt_load:
	lgdt [gdt_ptr]	; carica il GDT dal suo descrittore

	jmp 0x08:gdt_reset_data

gdt_reset_data:
	mov ax, 0x10	; adesso mi tocca impostare tutti i vecchi segmenti
	mov ds, ax				; al nuovo segmento dati che ho dichiarato nel GDT
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	ret

tss_load:
	mov ax, 0x18
	ltr ax
	ret

; Inizializzazione registri per la protected mode
init_pm:
	
	call gdt_reset_data
	
	mov ebp, 0x90000		; aggiorno la posizione dello stack, che si trova adesso
	mov esp, ebp			; al di sopra dello spazio libero

	call START_PM
