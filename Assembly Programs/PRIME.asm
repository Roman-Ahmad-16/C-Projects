.MODEL SMALL
.STACK 100H

.DATA
      MSG           DB 'ENTER A NUMBER TO CHECK =$'
      NUM           DB ?
      MSG_PRIME     DB , 0DH, 0AH, 'NUMBER IS PRIME$'
      MSG_NOT_PRIME DB , 0DH, 0AH, 'NUMBER IS NOT PRIME $'

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

                  MOV BL, 2

                  CMP NUM, 2
                  JE  PRIME

                  MOV AL, NUM
                  CMP AL, 1
                  JBE NOT_PRIME

      CHECK_LOOP:

                  MOV AL, NUM
                  MOV AH, 0
                  DIV BL

                  CMP AH, 0
                  JE  NOT_PRIME

                  INC BL

                  MOV AL, NUM
                  CMP BL, AL
                  JB  CHECK_LOOP
      PRIME:
                  LEA DX, MSG_PRIME
                  MOV AH, 09H
                  INT 21H
                  JMP EXIT

      NOT_PRIME:
                  LEA DX, MSG_NOT_PRIME
                  MOV AH, 09H
                  INT 21H

      EXIT:
                  MOV AH, 4CH
                  INT 21H

MAIN ENDP
END MAIN