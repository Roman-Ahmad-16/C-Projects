.model small
.stack 100h
.data
    input db 9 dup(?)   
.code
main proc 
    
    mov ax, @data
    mov ds, ax

    mov cx, 9          
    mov bl, 0       

input_loop: 

    mov ah, 01h
    int 21h             

    sub al, '0'        
    mov ah, 0           
    add bl, al          

    loop input_loop

    mov al, bl          

    mov ah, 4Ch
    int 21h
main endp
end main