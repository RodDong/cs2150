; mathlib.s 

    global product
    global power

    section .text

product:
    ; Subroutine body:
    xor rax, rax 	 ; zero out the return register
    xor r10, r10 	 ; zero out the counter i 
start:
    cmp r10, rsi 	 ; does i == n?
    je done         ; if so jump to done
    add rax, rdi      ; add the integer in the first parameter to the return register
    inc r10          ; increment the counter i
    jmp start        ; jump to the start of the loop
done:
    ret              ; return the number in the register

power:
    ; Subroutine body:
    xor rax, rax 	 ; zero out the return register
    mov rax, 1       ; set rax = 1
    xor r10, r10 	 ; zero out the counter i 
loop:
    cmp rsi, 0       ; does rsi = 0?
    je return         ; if rsi == 0, jump to done
recurssion:
    dec rsi          ; rsi--
    call power       ; call power(rdi, rsi--)
    mov rsi, rax     ; move value in rax into rsi
    call product     ; call product(rdi, rsi)
return:
    ret              ; return value in rax




