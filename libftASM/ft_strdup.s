global _ft_strdup

extern _malloc, _ft_strlen, _ft_memcpy

section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	push rax
	mov rdi, rax
	call _malloc
	pop rdx
	pop rsi
	mov rdi, rax
	call _ft_memcpy
	ret
