.MODEL SMALL
.STACK 100h
.DATA
.CODE
MAIN PROC
    MOV AX, @DATA        
    MOV DS, AX

    MOV CX, 10        
    
    PUSH 0               
    PUSH 1               

FIB_LOOP:
   
    POP BX               
    POP AX              

    PUSH AX              
    PUSH BX              
    CALL PRINT_NUM
    
    MOV DX, ' '
    INT 21h

    POP BX               
    POP AX              

    MOV DX, AX           
    ADD DX, BX           

    PUSH BX             
    PUSH DX            

    LOOP FIB_LOOP

    MOV AH, 4Ch
    INT 21h
MAIN ENDP

PRINT_NUM PROC
    MOV BX, 10           
    MOV DX, 0
    PUSH DX             

CONVERT_LOOP:
    MOV DX, 0           
    DIV BX              
    ADD DX, '0'          
    PUSH DX             
    CMP AX, 0           
    JNE CONVERT_LOOP

PRINT_DIGITS:
    POP DX             
    CMP DX, 0            
    JE DONE_PRINTING
    MOV AH, 02h          
    INT 21h
    JMP PRINT_DIGITS

DONE_PRINTING:
    RET
PRINT_NUM ENDP

END MAIN