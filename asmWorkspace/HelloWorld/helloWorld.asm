section .data			;assigns constant variables
	text1 db "Enter your name: "
	text2 db "Hello, "

section .bss
	userIn resb 32

section .text			;defines where code goe32
	global _start		;defines entry point

_start:
	call _askName
	call _getName
	call _printHelloName

	mov eax, 60
	mov edi, 1
	syscall			; syscall to call exit with error code 0

_askName:
	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, 17
	syscall			;print text1

	ret

_getName:
	mov rax, 0
	mov rdi, 0
	mov rsi, userIn
	mov rdx, 32
	syscall			;stores 32 bytes of input into name

	ret

_printHelloName:
	mov rax, 1
	mov rdi, 1
	mov rsi, text2
	mov rdx, 7
	syscall			;print text2

	mov rax, 1
	mov rdi, 1
	mov rsi, userIn
	mov rdx, 32
	syscall			;print name

	mov rax, 1
	mov rdi, 1
	mov rsi, 10
	mov rdx, 1
	syscall			;print newline

	ret
