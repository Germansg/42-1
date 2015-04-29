%define CALL(x) 0x2000000 | x
%define WRITE 0x4
%define READ  0x3
%define STDOUT 1

global _ft_cat

section .bss
	
buff:	 resb 0x200

section .text

_ft_cat:
	lea rsi, [rel buff]
	mov rdx, 0x200
	mov rax, CALL(READ)
	syscall
	jc _end
	cmp rax, 0
	jle _end
	push rdi
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, CALL(WRITE)
	syscall
	pop rdi
	jmp _ft_cat

_end:
	mov rax, 0
	ret
