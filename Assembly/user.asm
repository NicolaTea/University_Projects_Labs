global main
section .data
    text1 db 'What is ypur name? '
    text2 db 'Hello, '
section .bss
    name resb 16
section .text
main:
     call printText1
     call getName
     call printText2
     call printName

     mov rax,60
     mov rdi,0
     syscall

getName:
     mov rax,0
     mov rdi,0
     mov rsi,name
     mov rdx,16
     syscall
     ret

printText1:
     mov rax,1
     mov rdi,1
     mov rsi,text1
     mov rdx,19
     syscall
     ret

printText2:
     mov rax,1
     mov rdi,1
     mov rsi,text2
     mov rdx,7
     syscall
     ret

printName:
     mov rax,1
     mov rdi,1
     mov rsi,name
     mov rdx,16
     syscall
     ret
