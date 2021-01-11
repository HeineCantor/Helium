[extern main]
[extern _Z13kernel_loaderv]

[bits 16]

jmp switch_to_pm

%include "kernel/gdt.asm"
%include "kernel/protected_mode.asm"
%include "kernel/print_util_32.asm"

[bits 32]

START_PM:					; da qui in poi è PROTECTED MODE
	mov ebx, pm_label
	call print_string_32
	
	call _Z13kernel_loaderv
	call main
	
	jmp $

pm_label: db "[Helium OS] 32-BIT",0