; Carica un numero di settori (contenuti in DH) a partire dal settore in CL in ES:BX dal drive contenuto in DL
drive_read:
	push dx
	mov ah, 0x02	; modalità leggi da disco
	mov al, dh		; quanti settori devo leggere?
	mov ch, 0		; cilindro 0
	mov dh, 0		; testina 0
	
	int 0x13		; chiama il sistema
	
	jc disk_error	; se carry è settato, c'è stato un errore
	pop dx
	
	cmp dh, al		; il numero di settori letti è uguale al numero di settori da leggere?
	jne disk_error
	ret
	
	ret
	
disk_error:
	mov bx, DISK_ERROR
	jmp $
	
DISK_ERROR db "Errore di lettura disco",0
