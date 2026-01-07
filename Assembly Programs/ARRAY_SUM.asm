.MODEL SMALL
.STACK 100H

.DATA
    ARRAY DB 1,2,3
    MSG   DB 0DH, 0AH,  'ARRAY VALUES : $ '
    SUM   DB 0DH, 0AH,  'SUM OF ARRAY VALUES : $'


.CODE
MAIN PROC
                MOV  AX, @DATA
                MOV  DS, AX

                LEA  DX, MSG
                MOV  AH, 09H
                INT  21H

                MOV  CX,  3
                MOV  SI,  0
                MOV  BL , 0

    PRINT_LOOP:
                MOV  AL, ARRAY[SI]
                ADD  BL , AL

                ADD  AL, '0'

                MOV  DL, AL
                MOV  AH, 02H
                INT  21H

                MOV  DL,' '
                INT  21H

                INC  SI
                LOOP PRINT_LOOP

                LEA  DX, SUM
                MOV  AH, 09H
                INT  21H

                ADD  BL, '0'
                MOV  DL, BL
                MOV  AH, 02H
                INT  21H


                MOV  AH, 4CH
                INT  21H
MAIN ENDP
END MAIN
