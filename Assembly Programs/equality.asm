;Write a program to input two numbers from the user and check
;whether both numbers are equal or not in the assembly

.model small
.stack 100h
.data
    
    msg   db 'Numbers are equal$'
    msg_1 db 'Number are not equal $'
.code
main proc
     
     mov ax, @data
     mov ds, ax  
           
     mov ah, 01h 
     int 21h
     sub al, '0'
     
     mov bl, al
     
     mov ah, 01h
     int 21h
     sub al, '0'
     
     cmp al, bl
     je display
     
  not_equal:
     
     lea dx, msg_1
     mov ah, 09h
     int 21h
     
     jmp exit
     
  display:
     
     lea dx, msg
     mov ah, 09h 
     int 21h
     
  exit:
      
     mov ah, 4ch
     int 21h
         
main endp
end main