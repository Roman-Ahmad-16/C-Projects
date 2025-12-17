.model small

.stack 100h

.data

.code

first proc   
    

     
    mov ah , 01h
    int 21h
    
    mov dl, al     
    mov ah, 02h
    int 21h
    
    
first endp     

end first 



;OS ne rule bana rakha:

;Input char ? AL

;Print char ? DL 