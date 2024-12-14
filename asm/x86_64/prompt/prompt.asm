section .data
	prompt db "Enter an integer: ", 0
	format db "%d", 0

section .bss
	input resd 1					;reserve space for one 32 bit integer (4 bytes)

section .text
	global _start

_start:

	;print prompt
	mov rdi, prompt
	call printf

	;read intyeger input
	mov rdi, format
	mov rsi, input
	call scanf

	;now 'input' contains the users input
	;you can use it for further processing or printing

	;example: print the entered integer back to the user
	mov rdi, format
	mov rsi, input
	call printf

	;exit the program
	mov rdi, 0
	call exit
