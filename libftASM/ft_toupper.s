section .text

global _ft_toupper

_ft_toupper:
	jmp _ft_islower

_ft_islower:
	cmp rdi, 97
	jl 	_not
	cmp rdi, 122
	jg	_not
	jmp _next

_not:
	mov rax, rdi
	ret

_next:
	sub rdi, 32
	mov rax, rdi
	ret
