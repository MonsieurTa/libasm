section .text
global ft_strcmp

; rdi, rsi
ft_strcmp:
  push rbp
  mov rbp, rsp

  push rdi
  push rsi
  mov rax, 0x0

loop:
  mov al, [rdi]
  cmp al, [rsi]
  jne exit

  and al, [rsi]
  jz exit

  inc rdi
  inc rsi

  jmp loop

exit:
  mov al, [rdi]
  sub al, [rsi]
  movsx rax, al

  pop rsi
  pop rdi
  pop rbp
  ret
