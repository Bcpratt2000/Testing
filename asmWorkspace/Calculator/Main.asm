section .data
	text1 db "Enter first number:  ",10
	text2 db "Enter second number: ",10
	newline db 10

section .bss
	output resb 1
	val1 resb 1
	val2 resb 1

section .text
	global _start

_start:

	mov rax, 1
	mov rdi, 1
	mov rsi, text1
	mov rdx, 22
	syscall			;print text1

	mov rax, 0
	mov rdi, 0
	mov rsi, val1
	mov rdx, 1
	syscall			;get user input for value 1 and store it in val1

	call _newline

	mov rax, 1
        mov rdi, 1
        mov rsi, text2
        mov rdx, 22
        syscall                 ;print text2

	mov rax, 0
        mov rdi, 0
        mov rsi, val2
        mov rdx, 1
        syscall                 ;get  user input for value 2 and store it in val2

	call _printVal2

	call _newline

	mov rsp, val1		;store the first integer in %rsp
	sub rsp, 48		;converts into an integer between 0 and 9

	mov rbp, val2		;store the second integer in %rbp
	sub rbp, 48		;converts into an integer between 0 and 9

	add rsp, rbp		;add both user inputs and store them in rbp
;	add rsp, 48
	mov [output], rsp	;store the sum in $output

	mov rax, 1
	mov rdi, 1
        mov rsi, output
        mov rdx, 1
        syscall                 ;print $output

	mov rax, 60
	mov rdi, 0
	syscall			;Returns with exit code 0

	call _newline

	jmp _start		;loop endlessly

_newline:
	mov rax, 1
        mov rdi, 1
        mov rsi, newline
        mov rdx, 1
        syscall                 ;print text1
	ret

_printVal1:			;debug
	mov rax, 1
	mov rdi, 1
	mov rsi, val1
	mov rdx, 11
	syscall
	ret

_printVal2:			;debug
	mov rax, 1
	mov rdi, 1
	mov rsi, val2
	mov rdx, 11
	syscall
	ret
