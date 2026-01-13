;Write a program to input one number from the user and check
;whether the number is positive, negative, or zero in assembly

.model small
.stack 100h
.data
    num   db ?
    msg   db 10,13, 'Number is Negative$'
    msg_1 db 10,13, 'Number is Positive$'
    msg_2 db 10,13, 'Number is zero$'
.code
main proc
    
    mov ax, @data
    mov ds, ax
    
    mov ah, 01h
    int 21h
    
    cmp al, '-'
    je negative
    
    sub al, '0'
        
    cmp al, 1
    jge positive
    
    cmp al , 0
    je zero
    
 zero:
    
    lea dx, msg_2
    mov ah, 09h
    int 21h
    
    jmp exit
    
 positive:
 
    lea dx, msg_1
    mov ah, 09h
    int 21h
    
    jmp exit
    
 negative:
    
    lea dx, msg
    mov ah, 09h
    int 21h
    
    jmp exit
    
 exit:
    
    mov ah, 4ch
    int 21h
    
main endp
end main