section .text
global  ft_strlen

ft_strlen:
  push rbp
  mov rbp, rsp

  push rbx
  mov rax, 0
  mov rbx, rdi

test:
  cmp byte [rbx], 0x0
  jne redo
  jmp exit

redo:
  inc rax
  inc rbx
  jmp test

exit:
  pop rbx
  pop rbp
  ret
