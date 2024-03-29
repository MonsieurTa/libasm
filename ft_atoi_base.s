extern ft_strlen
global ft_atoi_base

;int ft_atoi_base(const char *str, int str_base);
section .text

ft_atoi_base:
  xor rax, rax
  sub rsp, 17
  mov byte [rsp-17], 0x0 ; sign
  mov [rsp-16], rdi ; str
  mov [rsp-8], rsi ; str_base

  jmp trim_whitespace

trim_whitespace:
  xor r10, r10
  mov rcx, [rsp-16]
  mov r10b, [rcx]

  cmp r10b, 0x20 ; " "
  je trim
  cmp r10b, 0xc  ; "\f"
  je trim
  cmp r10b, 0xa  ; "\n"
  je trim
  cmp r10b, 0xd  ; "\r"
  je trim
  cmp r10b, 0x9  ; "\t"
  je trim
  cmp r10b, 0xb  ; "\v"
  je trim

  jmp parse_plus_sign

trim:
  inc qword [rsp-16]
  jmp trim_whitespace

parse_plus_sign:
  cmp r10b, 0x2b  ; "+"
  jne parse_neg_sign

  inc qword [rsp-16]
  jmp parse_digit

parse_neg_sign:
  cmp r10b, 0x2d  ; "-"
  jne parse_digit

  mov byte [rsp-17], 1
  inc qword [rsp-16]
  jmp parse_digit

parse_digit:
  xor r10, r10
  mov rcx, [rsp-16]

  mov r10b, [rcx]
  sub r10b, 0x30;     ; check if "0"
  cmp r10b, 0x0
  jl exit
  cmp r10b, [rsp-8]
  jl add_digit

  sub r10b, 0x7       ; check if "A"
  cmp r10b, 0xa
  jl exit
  cmp r10b, [rsp-8]
  jl add_digit

  sub r10b, 0x20      ; check if "a"
  cmp r10b, 0xa
  jl exit
  cmp r10b, [rsp-8]
  jl add_digit

  jmp exit

add_digit:
  mul qword [rsp-8]  ; multiply result by base
  add rax, r10
  jmp redo

redo:
  xor r10, r10
  inc qword [rsp-16]  ; go to next character
  mov r10, [rsp-16]
  cmp [r10], byte 0x0 ; exit if null character
  je exit

  jmp parse_digit

apply_neg:
  xor r10, r10
  mov r10b, [rsp-17]
  neg r10
  mul r10

  mov byte [rsp-17], 0x0
  jmp exit

exit:
  cmp byte [rsp-17], 0x0  ; is it positive?
  jne apply_neg

  mov rdi, [rsp-16]
  add rsp, 17
  ret
