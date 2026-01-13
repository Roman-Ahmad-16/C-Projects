.model small 

.stack 100h 

.data
    msg db 'My First Assembly Language Program $'
    msg1 db 0dh , 0ah , 'Hello World! $'
.code

      first proc 
         mov ax, @data
         mov ds, ax
         
         mov ah, 09h
         mov dx, offset msg
         int 21h
         
         mov ah, 09h
         lea dx, msg1
         int 21h
          
         mov ah, 4ch                                    
         int 21h
      first endp
      end first