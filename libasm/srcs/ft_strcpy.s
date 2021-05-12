section .text
global _ft_strcpy

_ft_strcpy:
	mov rax, 0
	cmp byte[rsi], 0
	jz end
	jmp copy

copy:
	mov r8b, byte[rsi + rax]
	mov byte[rdi + rax], r8b
	add rax, 1
	cmp byte[rsi + rax], 0
	jz end
	jmp copy


end:
	mov rax, rdi
	ret
