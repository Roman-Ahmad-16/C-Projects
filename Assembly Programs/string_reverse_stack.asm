.MODEL SMALL
.STACK 100H

.DATA
    MSG1 DB 'Enter String: $'
    MSG2 DB 0AH,0DH,'Reverse String via Stack: $'

.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 09H
    LEA DX, MSG1
    INT 21H

    MOV CX, 0          

READ_LOOP:  

    MOV AH, 01H        
    INT 21H      
    
    CMP AL, 0DH        ; Check Enter key
    JE  DONE_INPUT
    
    MOV AH,0
    PUSH AX            
    INC CX             
    JMP READ_LOOP

DONE_INPUT:

    MOV AH, 09H
    LEA DX, MSG2
    INT 21H

PRINT_LOOP:
    CMP CX, 0
    JE  EXIT_PROG

    POP AX             
    MOV DL, AL
    MOV AH, 02H        
    INT 21H

    DEC CX
    JMP PRINT_LOOP

EXIT_PROG:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN