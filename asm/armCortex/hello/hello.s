	.global _start			//Define the entry point for the program
	.text				//Define the section of code

_start:
	//Write the string to stdout
	mov x0, 1			//File descriptor (1 is stdout)
	ldr x1, =msg			//Load the address of the message into x1
	mov x2, 14			//Length of string
	mov x8, 64			//System call number for write
	svc 0				//Make the systemcall

	mov x0, 0			//Return code 0 (successful exit)
	mov x8, 93			//Systemcall number for exit
	svc 0				//Make the system call to exit
//The msg string
msg:
	.asciz "Hello world!\n"		//Null terminated string
