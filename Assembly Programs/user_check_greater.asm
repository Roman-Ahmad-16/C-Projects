;Write a program to input three numbers from the user and display
;the largest number in assembly.

.model small
.stack 100h
.data
    input   db 3 dup(?)
    msg     db 10,13, 'The Largest value is: $'
    max_val db ?
.code
main proc
    
    mov ax, @data
    mov ds, ax
    
    lea si, input
    
    mov cx, 3
    
  input_numbers:
    
    mov ah, 01h
    int 21h
    
    sub al, '0'
    
    mov [si], al
    inc si
    
    loop input_numbers
    
    lea si, input
    mov al, [si]
    
    mov cx, 3
    
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