section .text

extern _write

global _ft_puts

_ft_puts:
	syscall _write
	