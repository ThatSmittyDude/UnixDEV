section .text
global main

main:
    mov rax, 0  ; Set return value to 0
    mov rdi, 1  ; Argument 1: file descriptor (stdout)
    mov rsi, message_1  ; Argument 2: message to print
    mov rdx, 36  ; Argument 3: length of message

    ; Call the write system call
    syscall

    mov rdi, 0  ; Argument 1: user input
    mov rsi, input_buffer  ; Argument 2: buffer to store input
    mov rdx, 1024  ; Argument 3: buffer size

    ; Call the read system call
    syscall

    mov rax, 0  ; Set return value to 0
    mov rdi, 1  ; Argument 1: file descriptor (stdout)
    mov rsi, message_2  ; Argument 2: message to print
    mov rdx, 36  ; Argument 3: length of message

    ; Call the write system call
    syscall

    mov rdi, 0  ; Argument 1: user input
    mov rsi, input_buffer  ; Argument 2: buffer to store input
    mov rdx, 1024  ; Argument 3: buffer size

    ; Call the read system call
    syscall

    mov rax, 0  ; Set return value to 0
    mov rdi, 1  ; Argument 1: file descriptor (stdout)
    mov rsi, message_3  ; Argument 2: message to print
    mov rdx, 36  ; Argument 3: length of message

    ; Call the write system call
    syscall

    mov rax, 60  ; Exit code 0
    syscall

section .data
message_1: db '***Run a few test laps. Note your lap times***', 10  ; Message 1
message_2: db 'What is an average lap time in seconds?: ', 10  ; Message 2
message_3: db 'Your recommended lap count: ', 10  ; Message 3
input_buffer: resb 1024  ; Buffer to store user input
