[bits 16]

; Predisposizione a passare alla protected mode
switch_to_pm:
	
	cli			; spegni qualsiasi tipo di interrupt fin quando non avremo
				; impostato il vettore di interrupt nella protected mode
				
	lgdt [gdt_descriptor]	; carica il GDT dal suo descrittore
	
	mov eax, cr0			; prendo il registro di controllo c0
	or eax, 0x1				; imposto il primo bit a 1, per passare alla protected mode
	mov cr0, eax			; lo rimetto al suo posto
	
	jmp CODE_SEGMENT:init_pm	; ho fatto un far jump a un nuovo segmento
								; in questo modo il code segment è stato aggiornato a quello che gli ho specificato
								; e la pipeline è stata buttata via, poiché poteva contenere ancora istruzioni a 16 bit
	
[bits 32]

; Inizializzazione registri per la protected mode
init_pm:
	
	mov ax, DATA_SEGMENT	; adesso mi tocca impostare tutti i vecchi segmenti
	mov ds, ax				; al nuovo segmento dati che ho dichiarato nel GDT
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	mov ebp, 0x90000		; aggiorno la posizione dello stack, che si trova adesso
	mov esp, ebp			; al di sopra dello spazio libero
	
	call START_PM
