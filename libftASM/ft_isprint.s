section .text

global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl _not
	cmp rdi, 126
	jg	_not
	jmp _is

_is:
	mov rax, 1
	ret

_not:
	mov rax, 0
	ret
