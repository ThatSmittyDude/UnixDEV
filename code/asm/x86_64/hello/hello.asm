; hello.asm

global _start

section .text
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, hello_world
    mov edx, len
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h

hello_world: db 'Hello, world!', 10
len equ $ - hello_world
