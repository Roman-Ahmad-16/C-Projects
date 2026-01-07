.model small

.stack 100h

.data

.code

first proc
        mov bl, 0
        mov cl, 5

  l1:
        add bl, 1
        mov dl, bl
        add dl, '0'
        mov ah, 02h
        int 21h

        cmp bl, cl
        jbe l1

        mov ah, 4ch
        int 21h
first endp

end first