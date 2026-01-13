;Write a program to display reverse 9-0 characters in one line using
;a loop.

.model small
.stack 100h 
.data
.code
main proc
    
    mov cx, 9
    mov dl, '9'
    
  print_digits:
     
    mov ah, 02h
    int 21h
    
    dec dl
    loop print_digits
    
    mov ah, 4ch 
    int 21h 
    
main endp
end main