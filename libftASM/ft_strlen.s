section .text
	global _ft_strlen

	_ft_strlen:
		mov al, 0x0
		mov rcx, -1
		cld
		repnz scasb
		not rcx
		lea rax, [rcx - 1]
		ret
