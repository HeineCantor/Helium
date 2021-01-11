global initialize_multitasking
global switch_to_task

extern current_task

initialize_multitasking:
    push eax

    mov eax, 0
    mov [edi], eax
    mov [edi + 8], eax

    mov eax, cr3
    mov [edi + 4], eax

    mov eax, 1
    mov [edi + 12], eax

    pop eax
    ret

switch_to_task:
    push eax
    push ebx

    mov eax, [esi]  ;vecchio task
    mov ebx, esp
    sub ebx, 8      ;va bene lo stack pointer ma togli i push (SE QUALCOSA NON FUNZIONA E' COLPA DI STA ROBA)
    mov [eax], ebx  ;carico nell'esp del vecchio task l'attuale stack pointer

    mov esp, [edi]          ;carica esp del prossimo task
    mov eax, [edi + 4]      ;cr3

    pop ebx
    pop eax
    ret