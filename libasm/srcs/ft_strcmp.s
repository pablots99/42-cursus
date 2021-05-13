section .text
global _ft_strcmp


_ft_strcmp:
	mov rax, 0
	jmp comp
comp:
	cmp byte[ rdi + rax], 0
	je end
	cmp byte[ rsi + rax], 0
	je end
	mov r8b, byte [rsi + rax]
	cmp byte[ rdi + rax], r8b
	jne end
	add rax, 1
	jmp comp

end:
	mov r8, 0
	mov r8b, byte[rsi + rax]
	cmp r8b, byte[rdi + rax]
	jb small
	cmp r8b, byte[rdi + rax]
	ja big
	mov rax, 0
	ret

big:
	mov rax,-1
	ret
small:
	mov rax, 1
	ret
