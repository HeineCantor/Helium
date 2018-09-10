; GDT
; per informazioni sulla struttura delle tabelle
; riferisciti al file GDT_STRUCTURE

gdt_start:		; inizio del gdt

gdt_null:		; descrittore nullo obbligatorio di 8 byte tutti nulli
	dd 0x0
	dd 0x0
	
gdt_code:		; descrittore del segmento CODE
	dw 0xffff		; LIMIT (15 - 0)
	dw 0x0			; BASE (15 - 0)
	db 0x0			; BASE (23 - 16)
	db 10011010b	; PRIMI FLAG e TYPE FLAG
	db 11001111b	; SECONDI FLAG e LIMIT (19 - 16)
	db 0x0			; BASE (31 - 24)

gdt_data:		; descrittore del segmento DATA
	dw 0xffff		; LIMIT (15 - 0)
	dw 0x0			; BASE (15 - 0)
	db 0x0			; BASE (23 - 16)
	db 10010010b	; PRIMI FLAG e TYPE FLAG
	db 11001111b	; SECONDI FLAG e LIMIT (19 - 16)
	db 0x0			; BASE (31 - 24)

gdt_end:		; questo label serve all'assembler per calcolare la grandezza del gdt

; DESCRITTORE
gdt_descriptor:
	dw gdt_end - gdt_start - 1	; la grandezza del GDT, ridotta di 1, cioè la vuole così non so perché
	dd gdt_start				; l'indirizzo a cui comincia il GDT
	
; COSTANTI UTILI

CODE_SEGMENT	equ	gdt_code - gdt_start
DATA_SEGMENT	equ gdt_data - gdt_start
