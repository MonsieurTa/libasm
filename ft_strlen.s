section .text
global  ft_strlen

ft_strlen:
  mov rax, 1
  mov rdi, 1
  mov rsi, ""
  mov rdx, 1
  syscall

  mov rax, 0
  ret
