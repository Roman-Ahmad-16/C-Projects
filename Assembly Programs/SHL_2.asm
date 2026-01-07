.MODEL SMALL
.STACK 100H
                          ;A--> 65    a--> 97
                          ;B--> 66    b--> 98
.DATA
    msg  db 'Enter Lowercase letter: $'
    msg1 db 0dh,0ah,'uppercase letter: $'
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
         not al
         and al, msg2

         mov ah, 02h
         mov dl, al
         int 21h

         mov ah, 4Ch
         int 21h

MAIN ENDP
END MAIN
 
 
;00000001  ---> 1
;00000010
;00000100
;00001000
;00010000
;00100000  ---> 32

;11011111  ----> not


;(and)
;01100001 ---> a
;11011111 ----> not al
;---------
;01000001      
;--------- 