.model small
.stack 100h
.data
     EVEN_MSG DB  0DH,0AH, 'NUMBER IS EVEN $ '
     ODD_MSG  DB  0DH,0AH, 'NUMBER IS ODD  $ '
     NUM DB ?
.code

first proc
           MOV AX, @DATA
           MOV DS, AX
           
           MOV AH, 01H
           INT 21H
           
           MOV NUM, AL
           SHR NUM, 1
           
           JC ODD          ; IF CARRY FLAG = 1 , GO TO ODD PART
           
         EVEN:
            LEA DX, EVEN_MSG
            MOV AH, 09H
            INT 21H
            JMP EXIST
         
         ODD:
            LEA DX, ODD_MSG
            MOV AH, 09H
            INT 21H
         EXIST:   
            MOV AH, 4CH
            INT 21H   
first endp
end first