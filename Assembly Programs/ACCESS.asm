.MODEL SMALL
.STACK 100H
.DATA
  MSG      DB 'Enter Password: $'
  MSG_2    DB 0dh,0ah, 'Access Granted!$'
  MSG_3    DB 0dh,0ah, 'Access Denied!$'
  PASSWORD DB '1234$'
  INPUT    DB 4<DUP>?
.CODE
MAIN PROC

              MOV  AX, @DATA
              MOV  DS, AX

              LEA  DX, MSG
              MOV  AH, 09H
              INT  21H

              LEA  SI, INPUT
              MOV  CX, 4

  PASS_INPUT:
              MOV  AH, 01H
              INT  21H

              MOV  [SI], AL
              INC  SI
              LOOP PASS_INPUT

              LEA  SI, INPUT
              LEA  DI, PASSWORD

              MOV  CX, 4

  CMP_LOOP:
              MOV  AL, [SI]
              CMP  AL, [DI]

              JNE  WRONG

              INC  SI
              INC  DI
              LOOP CMP_LOOP

              MOV  AH, 09H
              LEA  DX, MSG_2
              INT  21H
              JMP  EXIT

  WRONG:
              MOV  AH, 09H
              LEA  DX, MSG_3
              INT  21H

  EXIT:
              MOV  AH, 4CH
              INT  21H

MAIN ENDP
END MAIN