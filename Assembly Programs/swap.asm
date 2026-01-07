.model small
.stack 100h
.data
    msg   db "Enter two numbers for swaping:$"
    v1    db ?
    v2    db ?
    msg_1 db , 0dh,0ah , "Numbers after swap:$"
.code
main proc
         mov  ax, @data
         mov  ds, ax

         ;print message
         mov  ah, 09h
         lea  dx, msg
         int  21h

         ;first input
         mov  ah, 01h
         int  21h
         mov  v1, al
         sub  v1, '0'

         ;second input
         mov  ah, 01h
         int  21h
         mov  v2, al
         sub  v2, '0'

         mov  al, v1
         mov  bl, v2

         push ax
         push bx

         pop  ax
         pop  bx

         ;print first number
         mov  ah, 02h
         mov  dl, al
         add  dl, '0'
         int  21h

         ;print second number
         mov  ah, 02h
         mov  dl, bl
         add  dl, '0'
         int  21h

main endp
end main