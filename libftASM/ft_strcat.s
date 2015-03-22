section .text

global _ft_strcat

_ft_strcat:
	push rdi           ;Pour pas perdre le pointeur

_while:						;Me fais avancer jusqua la fin de la 1st chaine
	cmp BYTE[rdi], 0x0
	je _cat
	inc rdi
	jmp _while

_cat:						;Si je suis ici , je suis a la fin de la 1st , alors je commence a copier la 2nd
	cmp byte[rsi], 0x0
	je _end
	movsb
	jmp _cat

_end:
	pop rax
	ret
	