[bits 32]

; Stampa di una stringa
print_string_32:
	pusha
	mov edx, VIDEO_MEMORY			; questo indirizzo punterà alla memoria video
	mov ah, WHITE_ON_BLACK			; ah indica colore di sfondo e colore del testo
	
	string_loop:
		mov al, [ebx]				; prossimo carattere della stringa
		
		cmp al, 0					; la stringa è finita?
		je end_string_loop			; se sì finisci il ciclo
		
		mov [edx], ax				; metti ax nell'indirizzo contenuto in edx
		
		inc ebx						; ebx aumenta di 1 perché passa al prossimo carattere, quindi prossimo byte
		add edx, 2					; edx aumenta di 2 perché ogni carattere in memoria è composto da due byte
		jmp string_loop
	end_string_loop:		
		popa
		ret

; VARIABILI e COSTANTI

chars_written:	db 0

VIDEO_MEMORY 	equ 0xb8000			; dove inizia la memoria video
WHITE_ON_BLACK	equ 0x0f			; testo bianco, sfondo nero
