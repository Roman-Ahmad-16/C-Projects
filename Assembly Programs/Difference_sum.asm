.model small
.stack 100h
.data

    array  db 10, 40, 55, 90
    result db 10, 13, 'SUM = $'

.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    LEA SI, ARRAY
    MOV CX, 3
    MOV BL, 0

DIFF:

    MOV AL, [SI+1]
    SUB AL, [SI]

    ADD BL, AL
    INC SI

    LOOP DIFF

    LEA DX, RESULT
    MOV AH, 09H
    INT 21H

    mov ax, 0
    mov al, bl
    mov cx, 0

convert_loop:

    mov bl, 10
    div bl

    push ax
    inc cx

    mov ah, 0
    cmp al, 0

    jne convert_loop

print_loop:

    pop ax

    mov dl, ah
    add dl, '0'

    mov ah, 02h
    int 21h

    dec cx
    jnz print_loop

    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN