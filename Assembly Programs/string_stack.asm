.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 'Enter String: $'
    MSG2 DB 0DH, 0AH, 'Original Order: $'

.CODE
START:
    MOV AX, @DATA
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 09H
    INT 21H

    MOV CX, 0         

INPUT_LOOP:
    MOV AH, 01H        
    INT 21H
    
    CMP AL, 0DH        ; Check Enter Key
    JE  PREPARE_PRINT
    
    MOV AH, 0         
    PUSH AX           
    INC CX             
    JMP INPUT_LOOP

PREPARE_PRINT:

    LEA DX, MSG2
    MOV AH, 09H
    INT 21H

    JCXZ EXIT_PROG

    MOV BP, SP         
    
    MOV AX, CX
    MOV BX, 2
    MUL BX
    SUB AX, 2
    MOV SI, AX       

PRINT_LOOP:   

    MOV DX, [BP+SI]   
    MOV AH, 02H
    INT 21H
    
    SUB SI, 2        
    LOOP PRINT_LOOP

EXIT_PROG:
    MOV AH, 4CH
    INT 21H

END START