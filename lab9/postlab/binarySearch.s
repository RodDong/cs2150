global binarySearch

section .text

binarySearch:
    cmp rdx, 0
    jl end
    xor rax, rax                ;zero the rax
    xor r10, r10                ;zero mid
loop:
    cmp rsi, rdx                ;if low > high, jump to end
    jg end
    mov r10, rdx                ;mid=low+(high-low)/2
    sub r10, rsi
    shr r10, 1
    add r10, rsi
    cmp r10, rsi                ;if mid<low jump to end
    jl end
    cmp r10, rdx                ;if mid>high jump to end
    jg end
    cmp ecx, Dword [rdi+4*r10]  ;if(arr[mid] == target) jump to found
    je found
    cmp ecx, Dword [rdi+4*r10]
    jl greater                  ;if(arr[mid] > target)  jump to greater
    cmp ecx, Dword [rdi+4*r10]
    jg lesser                   ;if(arr[mid] < target)  jump to lesser
greater:
    dec r10                     ;mid--
    mov rdx, r10                ;high = mid
    jmp loop
lesser:
    inc r10                     ;mid++
    mov rsi, r10                ;low = mid
    jmp loop
found:
    mov rax, r10                ;return target index
    ret    
end:
    mov rax, -1                 ;not found, return -1
    ret