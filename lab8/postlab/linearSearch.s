; linearSearch.s 
    global linearSearch

    section .text
; parameter 1: pointer to the int arr rdi
; parameter 2: size of the arr rsi
; parameter 3: target int to find in the arr rdx
linearSearch:
    xor rax, rax            ; zero the return register
    xor r10, r10            ; zero the counter
    dec rsi                 ; size--
loop:
    cmp r10, rsi            ; compare the size of the array and the counter
    jge notFound            ; jump to the end if (counter >= size) 
    cmp edx, Dword [rdi+4*r10]    ; compare the target with arr[i] 
    je found                ; if (target == arr[i]) return the element
    inc r10                 ; counter++
    jmp loop                ; jump back to the start of the loop
found:
    mov rax, r10            ; rax = target
    ret                     ; return rax = found value
notFound:
    mov rax, -1             ; rax = -1
    ret                     ; return -1