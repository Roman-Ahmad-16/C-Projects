.MODEL SMALL

.STACK 100H           ;A--> 65     a-->97
                      ;B--> 66     b-->98
.DATA
      msg  db 'Enter the letter in upper case : $ '
      msg1 db 0dh, 0ah, 'Letter in lower case is : $'
      msg2 db ?
.CODE

FIRST PROC
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

            add msg2, 32

            mov ah, 02h
            mov dl, msg2
            int 21h

            mov ah, 4ch
            int 21h

FIRST ENDP
END FIRST