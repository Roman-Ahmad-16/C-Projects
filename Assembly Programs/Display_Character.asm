;Write a program to display A-Z characters in one line using a loop 

.model small
.stack 100h
.data
.code 
main proc
         
         mov cx, 26
         mov dl, 65
         
 Print_Character:    
        mov ah, 02h
        int 21h
            
        inc dl
        loop Print_Character
        
        mov ah, 4ch 
        int 21h
        
main endp
end main