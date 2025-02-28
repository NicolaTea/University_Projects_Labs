global main
section .data
    in_msg db 'Introdu un numar: ', 0
    msg_impar db "Numarul este impar.",10
    msg_par db "Numarul este par.",10
    converted_n resb 10    ;se rezerva spatiu pt nr convertit
    uinput_len equ 10
    uinput resb uinput_len
section .text
main:
;afis in_msg
    mov rax,1
    mov rdi,1
    mov rsi,in_msg
    mov rdx,18
    syscall

;citeste nr de la tastatura
    mov rax,0
    mov rdi,0
    mov rsi,uinput
	mov rdx,uinput_len
    syscall

   

converting_number:
    movzx rdx,byte [rsi]   ;movzx=move with zero extend...octet de la adresa de memorie specif de rsi in rdx
    test dl,dl             ; vf ==0 este zero, ceea ce înseamnă că am ajuns la sfârșitul șirului
    jz  convert_done

;vf caracterul este numeric
    cmp dl,'0'
    jl  convert_done        ; dacă nr< '0' termină conversia jl=jump if less than
    cmp dl,'9'
    jg  convert_done        ; dacă nr>'9' termină conversia jg= jump if greater than

    sub dl,'0'             ; conversie ASCII la valoare numerică
    imul rax,rcx           ; * rez parțial cu 10
    add rax,rdx            ; add caracter nou
    inc rsi                ; urm caracter
    jmp converting_number

;vf paritatea
convert_done:
    test al,1   ;instructiune logica 'AND'
    jz par_nr   ; sare direct la par_nr dacă ultimul bitul este 0 jz=jump if zero


impar_nr:
    mov rax,1
    mov rdi,1
    mov rsi,msg_impar
    mov rdx,20
    syscall

    mov rdi,converted_n  ;adresa nr convertit
    mov rsi,rax          ;val numerica in rax
    call int_to_ascii

    mov rax,1
    mov rdi,1
    mov rsi,converted_n
    mov rdx,10
    syscall



 par_nr:
    mov rax,1
    mov rdi,1
    mov rsi,msg_par
    mov rdx, 18
    syscall

    mov rdi, converted_n    ;adresa nr convertit
    mov rsi, rax            ;val numerica in rax
    call int_to_ascii

    mov rax,1
    mov rdi,1
    mov rsi,converted_n
    mov rdx,10
    syscall


int_to_ascii:
    mov rcx,10  	;baza de conversie
    mov rbx,0		;index initializat
    mov rdx,1		;lungime sir initializat



mov rax,60
mov rdi,0
syscall
