section .text
extern ft_strlen
global ft_strcpy

ft_strcpy:
  push rdi

  mov rdi, rsi
  call ft_strlen

  mov rdi, [rsp]
  push rsi
  inc rax           ; include \0

loop:
  cmp rax, 0x0
  je exit

  push rax
  mov al, [rsi]     ; use al, equivalent to rax but 1 byte
  mov [rdi], al
  inc rdi
  inc rsi

  pop rax
  dec rax
  jmp loop

exit:
  pop rsi
  pop rdi
  mov rax, rdi
  ret
