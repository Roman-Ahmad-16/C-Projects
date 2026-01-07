.MODEL SMALL
.STACK 100H
.DATA
    MSG     DB 'ENTER A NUMBER = $'
    FACTORS DB 0DH,0AH,'FACTORS ARE: $'
    NUM     DB ?
.CODE
MAIN PROC
                 MOV AX, @DATA
                 MOV DS, AX

                 LEA DX, MSG
                 MOV AH, 09H
                 INT 21H

                 MOV AH, 01H
                 INT 21H
                 SUB AL, 30H
                 MOV NUM, AL

                 LEA DX, FACTORS
                 MOV AH, 09H
                 INT 21H

                 MOV BL, 1

    FACTOR_LOOP:
                 MOV AL, NUM
                 MOV AH, 0
                 DIV BL

                 CMP AH, 0
                 JNE NEXT

                 MOV DL, BL
                 ADD DL, 30H
                 MOV AH, 02H
                 INT 21H

                 MOV DL, ' '
                 INT 21H

    NEXT:
                 INC BL
                 MOV AL, NUM
                 CMP BL, AL
                 JBE FACTOR_LOOP

                 MOV AH, 4CH
                 INT 21H
MAIN ENDP
END MAIN