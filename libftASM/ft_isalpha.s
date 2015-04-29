section .text

global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl 	_not
	cmp rdi, 122
	jg	_not
	cmp rdi, 91
	jl _is
	cmp rdi, 97
	jl _not

_is:
	mov rax, 1
	ret

_not:
	mov rax, 0
	ret
	