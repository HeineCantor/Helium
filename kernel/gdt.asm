; GDT
; per informazioni sulla struttura delle tabelle
; riferisciti al file GDT_STRUCTURE

gdt_start:		; inizio del gdt

gdt_null:		; descrittore nullo obbligatorio di 8 byte tutti nulli
	dd 0x0
	dd 0x0
	
gdt_kernel_code:		; descrittore del segmento CODE kernel
	dw 0xffff		; LIMIT (15 - 0)
	dw 0x0			; BASE (15 - 0)
	db 0x0			; BASE (23 - 16)
	db 0x9a			; PRIMI FLAG e TYPE FLAG
	db 0xcf			; SECONDI FLAG e LIMIT (19 - 16)
	db 0x0			; BASE (31 - 24)

gdt_kernel_data:		; descrittore del segmento DATA kernel
	dw 0xffff		; LIMIT (15 - 0)
	dw 0x0			; BASE (15 - 0)
	db 0x0			; BASE (23 - 16)
	db 0x92			; PRIMI FLAG e TYPE FLAG
	db 0xcf			; SECONDI FLAG e LIMIT (19 - 16)
	db 0x0			; BASE (31 - 24)

;gdt_user_code:		; descrittore del segmento CODE kernel
;	dw 0xffff		; LIMIT (15 - 0)
;	dw 0x0			; BASE (15 - 0)
;	db 0x0			; BASE (23 - 16)
;	db 0xfa			; PRIMI FLAG e TYPE FLAG
;	db 0xcf			; SECONDI FLAG e LIMIT (19 - 16)
;	db 0x0			; BASE (31 - 24)

;gdt_user_data:		; descrittore del segmento DATA kernel
;	dw 0xffff		; LIMIT (15 - 0)
;	dw 0x0			; BASE (15 - 0)
;	db 0x0			; BASE (23 - 16)
;	db 0xf2			; PRIMI FLAG e TYPE FLAG
;	db 0xcf			; SECONDI FLAG e LIMIT (19 - 16)
;	db 0x0			; BASE (31 - 24)

gdt_end:		; questo label serve all'assembler per calcolare la grandezza del gdt

; DESCRITTORE
gdt_descriptor:
	dw gdt_end - gdt_start - 1	; la grandezza del GDT, ridotta di 1
	dd gdt_start				; l'indirizzo a cui comincia il GDT
	
; COSTANTI UTILI

K_CODE_SEGMENT	equ	gdt_kernel_code - gdt_start
K_DATA_SEGMENT	equ gdt_kernel_data - gdt_start
;U_CODE_SEGMENT	equ gdt_user_code - gdt_start
;U_DATA_SEGMENT	equ gdt_user_data - gdt_start