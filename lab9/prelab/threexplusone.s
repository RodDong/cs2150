
global threexplusone

section .text

threexplusone:
    push r10
    xor rax, rax            ; zero rax
    xor r10, r10            ; zero the counter
loop:
    cmp rdi, 1              ; if param1 == 1, jump to end
    je end
    mov r11, 1              ; r11=1
    and r11, rdi            ; if rdi is even, jump to even(optimization: using and to compute the last bit)
    cmp r11b, 0
    je even
odd:
    mov rdi, rdi+rdi*2    ; rdi*=3 (optimization: using lea to compute multiplication)
    inc rdi                 ; rdi=3*rdi+1
    inc r10                 ; counter++
    call threexplusone      ; recurssion
    add r10, rax            ; store the r10 from the recurssion
    cmp rdi, 1
    je end
even:
    shr rdi, 1              ; rdi/=2
    inc r10                 ; counter++
    call threexplusone      ; jump to loop
    add r10, rax
    cmp rdi, 1
    je end
end:
    mov rax, r10
    pop r10
    ret
