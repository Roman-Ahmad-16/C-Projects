.model small
.stack 100h
.data
    ; Define an array of 5 numbers
    array db 3, 8, 1, 9, 4 
    msg db 'The Largest value is: $'
    max_val db ? 

.code
main proc
    mov ax, @data
    mov ds, ax

    lea si, array
    mov al, [si]
    
    mov cx, 5
   check_loop:
    cmp [si], al
    jle skip_update
    
    mov al, [si]
    skip_update:
    inc si
    loop check_loop
    
    mov max_val, al
    
    lea dx, msg
    mov ah, 09h
    int 21h
    
    mov dl, max_val
    add dl, '0'
    mov ah, 02h
    int 21h
    
    mov ah, 4ch
    int 21h
main endp
end main