section .text

global _ft_tolower

_ft_tolower:
	jmp _ft_isupper

_ft_isupper:
	cmp rdi, 65
	jl 	_not
	cmp rdi, 90
	jg	_not
	jmp _next

_not:
	mov rax, rdi
	ret

_next:
	add rdi, 32
	mov rax, rdi
	ret
