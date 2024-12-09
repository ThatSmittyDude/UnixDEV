.section .text
.global _start

_start:
	la sp, stack_top			#load the stack pointer with top of stack

	#system initialization
	call init_system

	#load kernel or program
	call load_program

	#transfer control to the loaded program
	jr ra

# system initialization routine
init_system:
	#add any hardware initialization here
	ret

#program loading routine
load_program:
	#load the program from a predefined location
	#lets assume the program is already in memory at 0x8000000

	la t0, 0x8000000			#load the addres of the program into t0
	jr t0					#jump to the programs entry point

#_define a stack

.section .bss
.align 12					#align the stack to a 4KB boundary
.space 4096					#allocate 4KB for the stack
stack_top:
