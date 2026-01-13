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
            
            MOV AH, 00     ; clear high byte , TO REMOVE GARBAGE VALUE 
            
            MOV BL, 2
            DIV BL
            
            CMP AH, 00
            
            JE EVEN       ; CONDITIONAL JUMP , WHEN CONDITION IS TRUE THEN JUMP
            
            JMP ODD       ; ES KE LY KOI CONDITION NAI HOTI JUMP KI 
            
          EVEN:
                LEA DX, MSG_EVEN
                MOV AH, 09H
                INT 21H
                JMP EXIST
          ODD:
                LEA DX, MSG_ODD
                MOV AH, 09H
                INT 21H 
                
          EXIST:
                MOV AH, 4CH
                INT 21H
                
FIRST ENDP
END FIRST
