extern __errno_location
global ft_write

section .text
ft_write:
  mov rax, 1
  syscall

  cmp rax, 0
  jl error
  ret

error:
  neg rax

  push rdi
  mov rdi, rax

  call __errno_location wrt ..plt
  mov [rax], rdi
  pop rdi

  mov rax, -1
  ret
