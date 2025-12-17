.model small

.stack 100h

.data
     msg db 0dh, 0ah, 'Multiply = $'
.code

first proc 
          mov ax, @data
          mov ds, ax
          
          mov bl, 0 
          mov cl, 3
          mov bh, 1
          
          l1:
            add bl, 1 
            
            mov al, bh    
            mul bl                    
            mov bh, al 
                
            mov dl, bl
            add dl, '0'
            mov ah, 02h
            int 21h
            
            cmp cl, bl
            ja l1
            
            lea dx, msg 
            mov ah, 09h
            int 21h
            
            mov dl, bh
            add dl, '0'
            mov ah, 02h
            int 21h 
            
            mov ah, 4ch
            int 21h 
          
first endp
end first 