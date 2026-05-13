.MODEL SMALL
.STACK 100H

.DATA
   
    board DB '1','2','3','4','5','6','7','8','9'

    curPlayer DB 'X'

    Welcome  DB 'TIC TAC TOE',13,10,'===========',13,10,'$'
    Line     DB ' -----------',13,10,'$'
    AskMove  DB 13,10,'Player - Choose (1-9): $'
    BadMove  DB 13,10,'Cell taken! Try again.',13,10,'$'
    mWin      DB 13,10,' WINS!',13,10,'$'
    mDraw     DB 13,10,'DRAW! No winner.',13,10,'$'
    Again    DB 'Play again? (Y/N): $'

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

RESTART:
    CALL RESET_BOARD
    MOV curPlayer, 'X'

TURN:
    CALL SHOW_BOARD

    ; Print ask message
    LEA DX, AskMove
    MOV AH, 09H
    INT 21H

    ; Print current player
    MOV DL, curPlayer
    MOV AH, 02H
    INT 21H

    ; Read one key
    MOV AH, 01H
    INT 21H

    ; Validate: must be '1' to '9'
    CMP AL, '1'
    JB  BAD
    CMP AL, '9'
    JA  BAD

    ; Check if cell is free
    MOV BL, AL
    SUB BL, '1'
    MOV BH, 0
    LEA SI, board
    ADD SI, BX
    MOV CL, [SI]
    CMP CL, 'X'
    JE  BAD
    CMP CL, 'O'
    JE  BAD

    ; Place the mark
    MOV AL, curPlayer
    MOV [SI], AL

    ; Check win
    CALL CHECK_WIN
    CMP AL, 1
    JE  WIN

    ; Check draw
    CALL CHECK_DRAW
    CMP AL, 1
    JE  DRAW

    ; Switch player
    CMP curPlayer, 'X'
    JE  SWITCH_TO_O
    MOV curPlayer, 'X'
    JMP TURN

SWITCH_TO_O:
    MOV curPlayer, 'O'
    JMP TURN

BAD:
    LEA DX, BadMove
    MOV AH, 09H
    INT 21H
    JMP TURN

WIN:
    CALL SHOW_BOARD

    ; Print winner name first
    MOV DL, curPlayer
    MOV AH, 02H
    INT 21H

    ; Print "WINS!" message
    LEA DX, mWin
    MOV AH, 09H
    INT 21H
    JMP ASK_REPLAY

DRAW:
    CALL SHOW_BOARD
    LEA DX, mDraw
    MOV AH, 09H
    INT 21H

ASK_REPLAY:
    LEA DX, Again
    MOV AH, 09H
    INT 21H
    MOV AH, 01H
    INT 21H
    AND AL, 0DFH
    CMP AL, 'Y'
    JE  RESTART

    MOV AH, 4CH
    INT 21H
MAIN ENDP

; ============================================
; RESET_BOARD - Fill board with '1' to '9'
; ============================================
RESET_BOARD PROC
    LEA SI, board
    MOV AL, '1'
    MOV CX, 9
FILL:
    MOV [SI], AL
    INC AL
    INC SI
    LOOP FILL
    RET
RESET_BOARD ENDP

; ============================================
; SHOW_BOARD - Print the 3x3 grid
; ============================================
SHOW_BOARD PROC
    ; Print header
    LEA DX, Welcome
    MOV AH, 09H
    INT 21H

    ; --- ROW 1 ---
    LEA DX, Line
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[0]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[1]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[2]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H

    ; --- ROW 2 ---
    LEA DX, Line
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[3]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[4]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[5]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H

    ; --- ROW 3 ---
    LEA DX, Line
    MOV AH, 09H
    INT 21H

    MOV AH, 02H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[6]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[7]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, board[8]
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, '|'
    INT 21H
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H

    ; Bottom border
    LEA DX, Line
    MOV AH, 09H
    INT 21H

    RET
SHOW_BOARD ENDP

; ============================================
; CHECK_WIN - Returns AL=1 if curPlayer won
; ============================================
CHECK_WIN PROC
    MOV CH, curPlayer

    ; Row 1: 0,1,2
    MOV AL, board[0]
    CMP AL, CH
    JNE ROW2
    MOV AL, board[1]
    CMP AL, CH
    JNE ROW2
    MOV AL, board[2]
    CMP AL, CH
    JNE ROW2
    MOV AL, 1
    RET

ROW2:
    MOV AL, board[3]
    CMP AL, CH
    JNE ROW3
    MOV AL, board[4]
    CMP AL, CH
    JNE ROW3
    MOV AL, board[5]
    CMP AL, CH
    JNE ROW3
    MOV AL, 1
    RET

ROW3:
    MOV AL, board[6]
    CMP AL, CH
    JNE COL1
    MOV AL, board[7]
    CMP AL, CH
    JNE COL1
    MOV AL, board[8]
    CMP AL, CH
    JNE COL1
    MOV AL, 1
    RET

COL1:
    MOV AL, board[0]
    CMP AL, CH
    JNE COL2
    MOV AL, board[3]
    CMP AL, CH
    JNE COL2
    MOV AL, board[6]
    CMP AL, CH
    JNE COL2
    MOV AL, 1
    RET

COL2:
    MOV AL, board[1]
    CMP AL, CH
    JNE COL3
    MOV AL, board[4]
    CMP AL, CH
    JNE COL3
    MOV AL, board[7]
    CMP AL, CH
    JNE COL3
    MOV AL, 1
    RET

COL3:
    MOV AL, board[2]
    CMP AL, CH
    JNE DIAG1
    MOV AL, board[5]
    CMP AL, CH
    JNE DIAG1
    MOV AL, board[8]
    CMP AL, CH
    JNE DIAG1
    MOV AL, 1
    RET

DIAG1:
    MOV AL, board[0]
    CMP AL, CH
    JNE DIAG2
    MOV AL, board[4]
    CMP AL, CH
    JNE DIAG2
    MOV AL, board[8]
    CMP AL, CH
    JNE DIAG2
    MOV AL, 1
    RET

DIAG2:
    MOV AL, board[2]
    CMP AL, CH
    JNE NO_WIN
    MOV AL, board[4]
    CMP AL, CH
    JNE NO_WIN
    MOV AL, board[6]
    CMP AL, CH
    JNE NO_WIN
    MOV AL, 1
    RET

NO_WIN:
    MOV AL, 0
    RET
CHECK_WIN ENDP

; ============================================
; CHECK_DRAW - Returns AL=1 if board is full
; ============================================
CHECK_DRAW PROC
    MOV CX, 9
    LEA SI, board
SCAN:
    MOV AL, [SI]
    CMP AL, 'X'
    JE  NEXT_CELL
    CMP AL, 'O'
    JE  NEXT_CELL
    MOV AL, 0
    RET
NEXT_CELL:
    INC SI
    LOOP SCAN
    MOV AL, 1
    RET
CHECK_DRAW ENDP

END MAIN