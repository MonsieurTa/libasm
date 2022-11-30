section .text
global ft_list_size

; int ft_lstsize(t_list *lst)
ft_list_size:
  push rbp
  mov rbp, rsp
  sub rsp, 0x8
  xor rax, rax

  cmp rdi, 0x0
  jle exit

  mov [rbp-8], rdi
  jmp loop

loop:
  mov rdx, [rbp-8]
  cmp rdx, 0x0
  jle exit

  mov rdx, [rdx+8]
  mov [rbp-8], rdx
  inc rax
  jmp loop

exit:
  mov rsp, rbp
  pop rbp
  ret
