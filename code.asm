section .text

global _start

_start:

    mov eax, 10
    mov ebx, 20
    mov ecx, 30
    mov edx, 40
    mov esi, 50
    mov edi, 60

    push eax
    push ebx
    push ecx
    push edx
    push esi
    push edi
