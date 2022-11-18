extern ft_strlen
global ft_atoi_base

;int ft_atoi_base(const char *str, int str_base);
section .text

ft_atoi_base:
  sub rsp, 32
  mov [rsp-32], rdi ; str
  mov [rsp-16], rsi ; str_base
  xor rax, rax

  jmp trim_whitespace

trim_whitespace:
  xor r10, r10
  mov rcx, [rsp-32]
  mov r10b, [rcx]

  cmp byte r10b, 0x20 ; " "
  je trim
  cmp byte r10b, 0xc  ; "\f"
  je trim
  cmp byte r10b, 0xa  ; "\n"
  je trim
  cmp byte r10b, 0xd  ; "\r"
  je trim
  cmp byte r10b, 0x9  ; "\t"
  je trim
  cmp byte r10b, 0xb  ; "\v"
  je trim

  jmp parse_digit

trim:
  inc qword [rsp-32]
  jmp trim_whitespace

parse_digit:
  xor r10, r10
  mov rcx, [rsp-32]

  mov r10b, [rcx]
  sub r10b, 0x30;     ; check if " "
  cmp r10b, [rsp-16]
  jl add_digit

  sub r10b, 0x7       ; check if "A"
  cmp r10b, [rsp-16]
  jl add_digit

  sub r10b, 0x20      ; check if "a"
  cmp r10b, [rsp-16]
  jl add_digit

  jmp exit

add_digit:
  mul qword [rsp-16]  ; multiply result by base
  add rax, r10
  jmp redo

redo:
  xor r10, r10
  inc qword [rsp-32]  ; go to next character
  mov r10, [rsp-32]
  cmp [r10], byte 0x0 ; exit if null character
  je exit

  jmp parse_digit

exit:
  mov rdi, [rsp-32]
  add rsp, 32
  ret
