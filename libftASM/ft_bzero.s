section .text

global _ft_bzero

_ft_bzero:
	cmp rsi, 1
	jl _stop
	cmp rdi, BYTE 0x0
	je _stop
	mov [rdi], BYTE 0x0
	inc rdi
	dec rsi
	jmp _ft_bzero

_stop:
	ret
