.model small
.stack 100h

.data

.code

first proc
     
    mov ah, 01h
    int 21h 
    sub al,'0'
    mov bl, al
    
    mov ah, 01h
    int 21h 
    sub al,'0'
    mov cl, al
    
    add bl, cl
    add bl, '0' 
    mov dl, bl
    
    mov ah , 02
    INT 21H
    
first endp

end first
