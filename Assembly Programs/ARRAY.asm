.MODEL SMALL
.STACK 100H

.DATA
      ARRAY DB 1,2,3,4,5,6
      MSG   DB 'ARRAY VALUES : $ ' 

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    
    LEA DX, MSG
    MOV AH, 09H
    INT 21H

    MOV CX, 5
    MOV SI, 0
    
PRINT_LOOP:
    MOV AL, ARRAY[SI]
    ADD AL, '0'
    
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    
    MOV DL,' '
    INT 21H
    
    INC SI
    LOOP PRINT_LOOP
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
