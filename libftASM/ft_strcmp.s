global _ft_strcmp

section .text

_ft_strcmp:
	mov al, byte[rdi]
	mov cl, byte[rsi]
	cmp cl, al
	jne _end
	cmp byte[rdi], 0x0
	je _end
	inc rdi
	inc rsi
	jmp _ft_strcmp

_end:
	mov bl, al
	sub bl, cl
	ret
