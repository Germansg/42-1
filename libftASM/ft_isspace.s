section .text
	global _ft_isspace

_ft_isspace:
	cmp		rdi, 32
	je		_endo
	cmp		rdi, 9
	je		_endo
	cmp		rdi, 13
	je		_endo
	jmp		_endz

_endo:
	mov		rax, 1
	ret

_endz:
	mov		rax, 0
	ret
