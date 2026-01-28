.MODEL SMALL
.STACK 100H

.DATA
    MSG DB 'FIBONACCI SERIES: $'
    A   DB 0
    B   DB 1
    TEMP DB ?

.CODE
MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        LEA DX, MSG
        MOV AH, 09H
        INT 21H
        
        MOV DL, A
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        CALL PRINT_SPACE
        
        MOV DL, B
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        CALL PRINT_SPACE
        
        MOV CL, 10 
        
    FIB_LOOP:
        MOV AL, A
        ADD AL, B    
        MOV TEMP, AL
        
        MOV AH, B
        MOV A, AH    
        MOV B, AL    
        
        MOV AH, 0
        MOV AL, TEMP
        MOV BL, 10
        DIV BL     
        
        MOV BH, AH   
        
        CMP AL, 0
        JE SINGLE_DIGIT
        
        MOV DL, AL
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        
    SINGLE_DIGIT:
   
        MOV DL, BH
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        
        CALL PRINT_SPACE
        
        DEC CL
        JNZ FIB_LOOP
        
        MOV AH, 4CH
        INT 21H
MAIN ENDP

PRINT_SPACE PROC
    MOV DL, ' '
    MOV AH, 02H
    INT 21H
    RET
PRINT_SPACE ENDP

END MAIN