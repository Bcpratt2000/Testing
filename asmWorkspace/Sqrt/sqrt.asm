section .data			;assigns constant variables

section .bss			;reserves memory
	input resb 8

section .text			;defines where code goes
	global _start		;defines entry point

_start:
	call getString
	call calc
	call print


	mov rax, 60
	mov rdi, 1
	syscall			; syscall to call exit with exit code 0

getString:
	mov rax, 0
	mov rdi, 0
	mov rsi, input
	mov rdx, 8
	syscall			;stores 8 byte int of input into input

	ret

calc:
	mov rax, input
	movq xmm0, rax
	cvtdq2pd xmm1, xmm0	;converts xxm0 into a double and stores it in xxm1
	sqrtpd xmm0, xmm1	;sqrt of xxm1 stored in xxm0
	
	ret

print:
	mov rax, 1
	mov rdi, 1
	movq rsi, xmm0
	mov rdx, 8
	syscall			;print xxm0

	mov rsi, 10
	mov rdx, 1
	syscall			;print newline

	ret
