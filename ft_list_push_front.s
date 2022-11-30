section .text
global ft_list_push_front

;void ft_lstadd_front(t_list **lst, t_list *new)
ft_list_push_front:
  cmp rsi, 0x0
  jle exit

  mov rax, [rdi]
  mov [rsi+8], rax ; new->next = first element of lst
  lea rax, [rsi]
  mov [rdi], rax ; set first element to new

  jmp exit

exit:
  mov rax, 0
  ret
