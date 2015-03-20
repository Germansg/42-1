section .text

global _ft_isalnum

_ft_isalnum:
	jmp _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl 	_isdigit
	cmp rdi, 122
	jg	_isdigit
	cmp rdi, 91
	jl _next
	cmp rdi, 97
	jl _isdigit
	jmp _next

_isdigit:
	cmp rdi, 48
	jl 	_not
	cmp rdi, 57
	jg	_not
	jmp _next

_not:
	mov rax, 0
	ret

_next:
	mov rax, 1
	ret
