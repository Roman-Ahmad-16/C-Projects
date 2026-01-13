.model small

.stack 100h

.data 
     msg db 0DH , 0AH, 'SUM = $'
.code 

first proc
    
                     
          mov ax, @data
          mov ds, ax
            
          mov bl, 0         ;counter
          mov cl, 3         ;limit
          mov bh, 0         ;sum
          
          l1:
            add bl, 1
            add bh, bl
            mov dl, bl 
            add dl, '0'
            mov ah, 02h
            int 21h 
                     
                     
            cmp cl, bl
            ja l1  

            ;message print 
            lea dx, msg
            mov ah, 09h
            int 21h 
            
            ;sum print
            mov dl, bh
            add dl, '0'
            mov ah, 02h
            int 21h
               
               
            mov ah, 4ch
            int 21h
first endp
end first