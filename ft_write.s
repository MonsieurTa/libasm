section .text
global ft_write

; ssize_t write(int fd, const void *buf, size_t count);
; rdi, rsi, rdx
ft_write:
  push rbp
  mov rbp, rsp

  mov rax, 1
  syscall

exit:
  pop rbp
  ret
