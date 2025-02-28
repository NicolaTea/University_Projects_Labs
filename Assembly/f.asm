global main

section .data

section .text

f:
mov ax,1
push ax
ret

g:
mov ax,2
ret

main:
xor rax,rax
call f
mov ax,3

mov rax,60
mov rdi,0
syscall

