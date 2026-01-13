;Write a program to input two or three numbers from the user and add
;them then display its result in assembly.

.model small
.stack 100h
.data
    input  db 9 dup(?) 
    result db 10 , 13 , 'Sum = $'
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea si, input
    
    mov cx, 9
    
    mov bl, 0
    
 input_loop:
 
    mov ah, 01h
    int 21h
    
    sub al, '0'
    mov [si], al
    add bl, [si]
    
    inc si
    
    loop input_loop
    
    lea dx, result
    mov ah, 09h
    int 21h
    
    mov ax, 0
    
    mov al, bl
   
    mov cx, 0
    
 convert_loop:
 
    mov bl, 10
    div bl
    
    push ax
    inc cx
    
    mov ah, 0
    cmp al, 0
    
    jne convert_loop
 
 print_loop:
 
    pop ax
    
    mov dl, ah
    add dl, '0'
    
    mov ah, 02h 
    int 21h
    
    dec cx
    jnz print_loop
   
    mov ah, 4ch 
    int 21h
 
main endp
end main