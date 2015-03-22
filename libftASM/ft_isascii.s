section .text

global _ft_isascii

_ft_isascii:
	cmp rdi, 0
	jl _not
	cmp rdi, 127
	jg	_not
	jmp _is

_is:
	mov rax, 1
	ret

_not:
	mov rax, 0
	ret
