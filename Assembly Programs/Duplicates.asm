;Write a program to display all element of array having same
;elements.

.model small
.stack 100h
.data
    array db 4 dup(?)   
    msg   db 10, 13, 'Duplicates: $'
.code
main proc
    mov ax, @data
    mov ds, ax

    lea si, array
    mov cx, 4
input:
    mov ah, 01h
    int 21h
    sub al, '0'        
    mov [si], al
    inc si
    loop input

    lea dx, msg
    mov ah, 09h
    int 21h

    lea si, array
    mov cx, 4           
outer_loop:
    push cx            
    mov al, [si]       
    
    mov di, si
    inc di
    dec cx              
    jz next_outer       

inner_compare:
    cmp al, [di]        
    je found_equal
    jmp continue_inner

found_equal:
 
    mov dl, al
    add dl, '0'        
    mov ah, 02h
    int 21h
      
    mov dl, ' '
    int 21h

continue_inner:
    inc di
    loop inner_compare

next_outer:
    pop cx            
    inc si
    loop outer_loop

    mov ah, 4ch
    int 21h
main endp
end main