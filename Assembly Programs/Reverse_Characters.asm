;Write a program to display reverse Z-A characters in one line using
;a loop.

.model small
.stack 100h 
.data
.code
main proc
        
        mov cx, 26
        mov dl, 'Z'
        
    Print_Characters:
        
        mov ah, 02h
        int 21h
        
        dec dl
        loop Print_Characters
        
        mov ah, 4ch
        int 21h
        
main endp
end main