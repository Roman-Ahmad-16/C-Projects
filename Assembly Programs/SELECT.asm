.MODEL SMALL
.STACK 100H
.DATA
    NUM    DB ?
    CHOICE DB ?
    MSG        DB 0DH, 0AH, "ENTER CHOICE: $"
    MSG_1      DB 0DH, 0AH, "PRESS 0 FOR PRIME AND 1 FOR EVEN/ODD: $"
    MSG_NUM    DB 0DH, 0AH, "ENTER A SINGLE DIGIT NUMBER: $"
    PRIME_MSG  DB 0DH, 0AH, "NUMBER IS PRIME $"
    NOT_PRIME  DB 0DH, 0AH, "NUMBER IS NOT PRIME $"
    EVEN_MSG   DB 0DH, 0AH, "NUMBER IS EVEN $"
    ODD_MSG    DB 0DH, 0AH, "NUMBER IS ODD $"
.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    LEA DX, MSG
    MOV AH, 09H
    INT 21H
    
    LEA DX, MSG_1
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    MOV CHOICE, AL
    SUB CHOICE, '0'  
    
    LEA DX, MSG_NUM
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, '0'      
    MOV NUM, AL
    
    CMP CHOICE, 1
    JE EVEN_ODD
    
    ; ===== PRIME CHECKING =====
    CMP NUM, 2
    JE PRIME
    
    CMP NUM, 1
    JBE NO_PRIME
    
    MOV BL, 2        
    
CHECK_LOOP:
    MOV AX, 0        
    MOV AL, NUM      
    DIV BL           
    
    CMP AH, 0        
    JE NO_PRIME      
    
    INC BL         
    
    MOV AL, NUM
    CMP BL, AL      
    JB CHECK_LOOP    
    
   
    JMP PRIME
    
    ; ===== EVEN/ODD CHECKING =====
EVEN_ODD:
    MOV AL, NUM
    SHR AL, 1
    JC ODD
    
    TEST AL, 1       
    JNZ ODD          
    
EVEN:
    LEA DX, EVEN_MSG
    MOV AH, 09H
    INT 21H
    JMP EXIST
    
ODD:
    LEA DX, ODD_MSG
    MOV AH, 09H
    INT 21H
    JMP EXIST
    
PRIME:
    LEA DX, PRIME_MSG
    MOV AH, 09H
    INT 21H
    JMP EXIST
    
NO_PRIME:
    LEA DX, NOT_PRIME
    MOV AH, 09H
    INT 21H
    
EXIST:
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
END MAIN