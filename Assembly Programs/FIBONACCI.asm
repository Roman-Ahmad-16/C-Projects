.MODEL SMALL
.STACK 100H

.DATA
    MSG DB 'FIBONACCI SERIES: $'
    A   DB 0
    B   DB 1

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
        
        MOV DL, ' '
        INT 21H
        
        MOV DL, B
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        
        MOV DL, ' '
        INT 21H
        
        MOV CL, 5
        
     FIB_LOOP:
        MOV AL, A
        ADD AL, B
        
        MOV AH, B
        MOV A,  AH
        
        MOV B,  AL
        
        MOV DL, AL
        ADD DL, 30H
        MOV AH, 02H
        INT 21H
        
        MOV DL, ' '
        INT 21H
        
        DEC CL
        JNE FIB_LOOP
        
        MOV AH, 4CH
        INT 21H
        
MAIN ENDP
END MAIN