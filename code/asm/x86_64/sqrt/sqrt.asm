section .data
	number dq 25.0				;the number whose square root we want to find

section .bss
	result resq 1				;reserve space for the result

section .text
	global _start

_start:
	;load the number into the FPU register stack
	fld qword [number]			;load the number (25.0) onto the FPU stack

	;compute the square root
	fsqrt					;compute the square root

	;store the result from the FPU register stack
	fstp qword [result]			;store the result (result now contains sqrt(25.0))

	;exit the program (just for the sake of having a complete example)
	mov rax, 60				;syscall: exit
	xor rdi, rdi				;status: 0
	syscall

section .bss
	result resq 1				;reserve space for the result
