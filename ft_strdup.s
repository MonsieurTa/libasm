extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

section .text

ft_strdup:
  call ft_strlen
  push rsi
  push rdi

  inc rax
  mov rdi, rax
  call malloc wrt ..plt

  mov rdi, rax
  pop rsi
  call ft_strcpy ; can be optimized by using strncpy, but whatever

  mov rdi, rsi
  pop rsi
  ret
