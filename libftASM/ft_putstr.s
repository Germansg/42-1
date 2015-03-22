%define CALL(x) 0x2000000 | x
%define WRITE 0x4

%define STDOUT 0x1


global _ft_putstr
extern _ft_strlen

section .data
null:
	.string db "(null)"
	
section .text

_ft_putstr:
	cmp rdi, 0x0
	je _null
	push rdi
	call _ft_strlen
	mov	rdx, rax
	pop rsi
	mov rdi, STDOUT
	mov rax, CALL(WRITE)
	syscall
	jmp _end

_null:
	mov rdi, STDOUT
	lea rsi, [rel null.string]
	mov rdx, 6
	mov rax, CALL(WRITE)
	syscall
	jmp _end

_end:
	mov rax, 0xa
	ret
	