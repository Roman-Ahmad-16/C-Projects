.MODEL SMALL

.STACK 100H

.DATA
      MSG_EVEN   DB ' NUMBER IS EVEN $'
      MSG_ODD    DB ' NUMBER IS ODD $ '
      USER_INPUT DB ?
.CODE

FIRST PROC
            MOV AX, @DATA
            MOV DS, AX

            MOV AH, 01H
            INT 21H

            SUB AL, '0'
            MOV USER_INPUT, AL

            MOV AH, 00              

            MOV BL, 2
            DIV BL

            CMP AH, 00

            JE  EVEN                

            JMP ODD                 

      EVEN:
            LEA DX, MSG_EVEN
            MOV AH, 09H
            INT 21H
            JMP EXIT
      ODD:
            LEA DX, MSG_ODD
            MOV AH, 09H
            INT 21H

      EXIT:
            MOV AH, 4CH
            INT 21H

FIRST ENDP
END FIRST
