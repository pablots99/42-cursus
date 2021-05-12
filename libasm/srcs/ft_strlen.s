
section .text
global _ft_strlen

_ft_strlen:
	mov rax, 0
	cmp byte [rdi], 0
	jz end
	jmp count

count:
	add rax, 1
	add rdi,1
	cmp byte [rdi], 0
	jz end
	jmp count

end:
	ret

