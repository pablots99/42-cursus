section .text
global _ft_strdup

extern _malloc
extern _ft_strlen
extern _ft_strcpy
_ft_strdup:
	mov rax ,0
	mov r8,rdi
	call _ft_strlen
	add rax, 1
	mov  rdi,rax
	call _malloc
	mov rdi, rax
	mov rsi, r8
	call _ft_strcpy
	ret
