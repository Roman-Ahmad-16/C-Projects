.MODEL SMALL
.STACK 100H
.DATA
    msg_input  DB 'Enter a number (0-3): $'
    msg_result DB 0DH, 0AH, 'The Factorial is: $'

.CODE
MAIN PROC

                MOV  AX, @DATA
                MOV  DS, AX

                LEA  DX, msg_input
                MOV  AH, 09H
                INT  21H

                mov  ah, 01h
                int  21H

                sub  al, '0'
                mov  cl, al

                xor  ch, ch

                mov  ax, 1

                cmp  cx, 0
                je   display

    check_loop:
                mul  cx
                loop check_loop
    display:
                mov  bx, ax

                LEA  DX, msg_result
                MOV  AH, 09H
                INT  21H

                MOV  DL, BL
                ADD  DL, '0'

                MOV  AH, 02H
                INT  21H

                mov  ah, 4ch
                int  21H
main endp
end main     