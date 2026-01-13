;Write a program to display 0-9 characters in one line using a loop

.model small
.stack 100h 
.data
.code
main proc
        
        mov cx, 10
        mov dl, '0'
        
    Print_Characters:
        
        mov ah, 02h
        int 21h  
        
        add al, '0'
        
        inc dl
        loop Print_Characters
        
        mov ah, 4ch
        int 21h
        
main endp
end main