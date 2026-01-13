;Write a program to take an array in assembly and display its first
;element.

.model small
.stack 100h
.data
    array db 4 dup(?)
    msg   db 10,13,'First Number = $'
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
         
         mov dl, [si]
         add dl, '0'
         mov ah, 02h
         int 21h
         
main endp
end main