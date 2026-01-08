.MODEL SMALL
.STACK 100H

.DATA

    STR1    DB 'MADAM$'       
    
    MSG_YES DB 10,13, 'The string is a PALINDROME.$'
    MSG_NO  DB 10,13, 'The string is NOT a palindrome.$'

.CODE
MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    LEA SI, STR1

    LEA DI, STR1
    
FIND_END:
    MOV AL, [DI]       
    CMP AL, '$'        
    JE  SET_DI_BACK     
    INC DI              
    JMP FIND_END

SET_DI_BACK:
    DEC DI           

CHECK_LOOP:
    CMP SI, DI          
    JAE IS_PALINDROME   
    
    MOV AL, [SI]        
    MOV BL, [DI]        
    
    CMP AL, BL          
    JNE NOT_PALINDROME  
    
    INC SI              
    DEC DI              
    JMP CHECK_LOOP      

IS_PALINDROME:
    LEA DX, MSG_YES     
    MOV AH, 09H         
    INT 21H
    JMP EXIT_PROG       

NOT_PALINDROME:
    LEA DX, MSG_NO      
    MOV AH, 09H         
    INT 21H

EXIT_PROG:
  
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN