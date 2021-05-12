section .text
global _ft_strcmp


_ft_strcmp:
	mov rax, 0
	cmp byte[rdi + rax], byte[rsi + rax]
	jz end
	jmp comp

comp:



end:
	ret
