section .text

global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48
	jl 	_not
	cmp rdi, 57
	jg	_not
	jmp _is

_is:
	mov rax, 1
	ret

_not:
	mov rax, 0
	ret
