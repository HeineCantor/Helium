; IMPOSTAZIONI INIZIALI
[org 0x7c00]				; organizzo la memoria per partire con la lettura dei dati da 0x7c00

; Stack
mov bp, 0x8000				; base dello stack
mov sp, bp					; stack pointer per ora è sulla base

; CODICE
mov [BOOT_DEVICE], dl		; in dl c'è il drive di avvio (il drive su cui c'è questo codice)
call clear_all				; pulisci lo schermo

mov bx, os_label			; varie stampe di stringhe
call print_string

mov bx, os_version
call print_string

call new_line

mov bx, device_label
call print_string

mov dx, [BOOT_DEVICE]
call print_hex

call load_kernel

mov dx, [KERNEL_ADDR]
call print_hex				; cosa ho letto nel disco?

call switch_to_pm			; passo alla PROTECTED MODE

jmp $						; loop infinito

%include "include/print_util.asm"
%include "gdt.asm"
%include "include/print_util_32.asm"
%include "include/protected_mode.asm"
%include "include/drive_util.asm"

[bits 16]

load_kernel:
	mov dl, [BOOT_DEVICE]		; leggo un'area di memoria e la inserisco in RAM all'indirizzo 0x9000
	mov cl, 2
	mov dh, 5
	mov bx, 0
	mov es, bx
	mov bx, KERNEL_ADDR

	call drive_read

	ret

[bits 32]

START_PM:					; da qui in poi è PROTECTED MODE
	mov ebx, pm_label
	call print_string_32
	
	jmp KERNEL_ADDR
	
	jmp $

; VARIABILI

os_label: db "[Helium OS]",0
os_version: db "VER:0.1",0
pm_label: db "[Helium OS] 32-BIT",0
device_label: db "BOOT DEVICE: ",0
err_label: db "ERRORE",0

BOOT_DEVICE: db 0

KERNEL_ADDR equ 0x1000

; PADDING E FIRMA

times 510-($-$$) db 0	; riempi tutto con gli 0

dw 0xaa55

; DATI A CASO

;times 512 dw 0xfafa
;times 512 dw 0xbebe
;times 512 dw 0xaaaa
;times 512 dw 0xbafa
