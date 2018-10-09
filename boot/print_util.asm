; IMPOSTA POSIZIONE CURSORE
set_cursor_pos:
	pusha
	mov ah, 0x02
	int 0x10
	popa
	ret
	
; PULISCI SCHERMO

clear_all:
	pusha
	mov ax, 0x0700		; modalità scorri giù, opzione pulisci schermo
	mov bh, 0x0f		; sfondo nero, scritte bianche
	mov cx, 0x0000		; RIGAxCOLONNA in alto a sinistra
	mov dx, 0x184f		; RIGAxCOLONNA in basso a destra (riga 18H, colonna 4fH)
	int 0x10			; pulisci lo schermo
	mov bh, 0
	mov dl, 0
	mov dh, 0
	call set_cursor_pos	; rimetti il cursore all'inizio
	popa
	ret

; STAMPA CARATTERE
print_char:
	push ax				; conservo ax
	mov ah, 0x0e		; modalità scrivi quello che sta in al
	int 0x10			; STAMPA
	pop ax				; riprendo ax
	ret
	
; STAMPA STRINGA
print_string:
	push ax
	chk_string:
		mov al, [bx]
		cmp al, 0
		je end_string
		call print_char
		inc bx
		jmp chk_string
	end_string:
		call new_line
		pop ax
		ret
		
; STAMPA DI UN NUMERO ESADECIMALE
print_hex:
	; scrittura di 0x
	mov al, '0'
	call print_char
	mov al, 'x'
	call print_char
	
	; ciclo di controllo
	mov bx, 0
	hex_check:
		cmp bx, 4
		jge end_check
		rol dx, 4				; ruota i 16 bit a sinistra per fare in modo che gli ultimi 4 bit diventino i primi, e così via
		mov cx, dx				; muovo in un registro supplementare
		and cx, 0x000f			; prendo solo i 4 bit di destra
		cmp cx, 9				; è un numero?
		jle num_hex				; se si trasformalo come un numero
		let_hex:				; se no trasformalo come una lettera
			sub cx, 9			
			or cx, 0x0060		; prefisso per le lettere minuscole: 6
			jmp end_routine		; stampa
		num_hex:				
			or cx, 0x0030		; prefisso per i numeri: 3
			jmp end_routine		; stampa
		end_routine:
			mov al, cl
			call print_char
			inc bx
			jmp hex_check
		end_check:
			call new_line
			ret
		
; A CAPO
new_line:
	push ax
	push bx
	mov ah, 0x03
	mov bh, 0
	int 0x10
	inc dh
	mov dl, 0
	call set_cursor_pos
	pop bx
	pop ax
	ret

; VARIABILI e DICHIARAZIONI

; Costanti
screen_width 	equ 80
screen_height 	equ 60
