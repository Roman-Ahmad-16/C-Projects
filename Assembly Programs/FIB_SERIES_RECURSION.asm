.model small
.stack 100h
.data
    first  dw 0
    second dw 1  
    msg    db 'Fibonacci Series: $'

.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg
    mov ah, 09h
    int 21h

    mov cx, 16 
    
    call FibonacciRecursive

    mov ah, 4ch
    int 21h
main endp

FibonacciRecursive proc   
    
    cmp cx, 0
    jz exit_proc

    push cx            
    
    mov ax, first
    call PrintNumber

    mov dl, ' '
    mov ah, 02h
    int 21h

    mov ax, first
    add ax, second      
    mov bx, second
    mov first, bx       
    mov second, ax     

    pop cx              
    dec cx
    call FibonacciRecursive

exit_proc:
    ret
FibonacciRecursive endp

PrintNumber proc
    push ax
    push bx
    push cx
    push dx

    mov cx, 0        
    mov bx, 10        

divide_loop:
    mov dx, 0
    div bx             
    push dx            
    inc cx
    cmp ax, 0
    jne divide_loop

display_loop:
    pop dx             
    add dl, 30h       
    mov ah, 02h
    int 21h
    loop display_loop

    pop dx
    pop cx
    pop bx
    pop ax
    ret
PrintNumber endp

end main