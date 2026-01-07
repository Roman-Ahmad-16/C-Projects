.MODEL SMALL
.STACK 100H
                          ;A--> 65    a--> 97
                          ;B--> 66    b--> 98
.DATA
    msg  db 'Enter uppercase letter: $'
    msg1 db 0dh,0ah,'Lowercase letter: $'
    msg2 db ?

.CODE
MAIN PROC
         mov ax, @data
         mov ds, ax


         mov ah, 09h
         lea dx, msg
         int 21h

         mov ah, 01h
         int 21h

         mov msg2, al

         mov ah, 09h
         lea dx, msg1
         int 21h

         mov al, 1
         shl al, 5

         or  al, msg2

         mov ah, 02h
         mov dl, al
         int 21h

         mov ah, 4Ch
         int 21h

MAIN ENDP
END MAIN
