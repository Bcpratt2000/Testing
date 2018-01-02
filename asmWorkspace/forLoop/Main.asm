section .data
	text db "Hello, World!", 10
	newline db 10
section .bss
	index resb 16

section .text
	global _start

_start:
	mov r8, 0		;loop counter

	call _loop

	mov rax, 60
	mov rdi, 0
	syscall			;exit with code 0

_printIndex:
	mov rax, r8		;stores index in rax
	add rax, 48		;turns rax into ascii number by adding 48
	mov [index], rax	;stores rax in &index

	mov rax, 1
	mov rdi, 1
	mov rsi, index
	mov rdx, 15
	syscall			;print index

	mov rax, 1
        mov rdi, 1
        mov rsi, newline
        mov rdx, 1
        syscall			;print newline
        ret

_loop:
	call _printIndex
	add r8, 1		;decrements r8
	cmp r8, 80
	jne _loop		;if r8!=0 lump to _loop
	ret			;else break
