.MODEL SMALL
.STACK 100H
.DATA
    MAIN_MSG DB 0DH , 0AH,'--- MAIN MENU ---'     , 0DH, 0AH, '$'
    OPT_1    DB '1. Employee Management', 0DH, 0AH, '$' 
    OPT_2    DB '2. Payroll Management' , 0DH, 0AH, '$'
    OPT_3    DB '3. Reports'            , 0DH, 0AH, '$'
    OPT_4    DB '4. Exit'               , 0DH, 0AH, '$'
    CHOICE   DB 'Enter your choice:$'
    INVALID  DB 0DH , 0AH, 'Invalid Choice! Try again.', 0DH , 0AH,'$'
    
    ;--- EMPLOYEE MANAGEMENT ---
    
    EMP_MENU_MSG DB 0DH, 0AH, '--- EMPLOYEE MANAGEMENT ---' , 0DH, 0AH, '$'
    EMP_ADD      DB '1. Add Employee' , 0DH, 0AH, '$'
    EMP_EDIT     DB '2. Edit Employee', 0DH, 0AH, '$'
    EMP_VIEW     DB '3. View Employee', 0DH, 0AH, '$'
    EMP_DEL      DB '4. Delete Employee', 0DH, 0AH, '$'
    EMP_BACK     DB '5. Back To Main Menu', 0DH, 0AH, '$'
    
        
    ;--- PAYROLL MANAGEMENT ---
    
    P_MENU_MSG DB 0DH, 0AH, '--- PAYROLL MANAGEMENT ---' , 0DH, 0AH, '$'
    P_CALC     DB '1. Calculate Salary' , 0DH, 0AH, '$'
    P_SLIP     DB '2. Generate Pay Slip', 0DH, 0AH, '$'
    P_SRCH     DB '3. Search Payroll', 0DH, 0AH, '$'
    P_BACK     DB '4. Back To Main Menu', 0DH, 0AH, '$'
    
                
    ;--- REPORTS MANAGEMENT ---
    
    R_MENU_MSG DB 0DH, 0AH, '--- REPORTS MANAGEMENT ---' , 0DH, 0AH, '$'
    R_ALL      DB '1. All Employees' , 0DH, 0AH, '$'
    R_SAL      DB '2. Salary Report', 0DH, 0AH, '$'
    R_DEPT     DB '3. Department-Wise Report', 0DH, 0AH, '$'
    R_BACK     DB '4. Back To Main Menu', 0DH, 0AH, '$'
    
.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    ;MENU PRINT 
    
DISPLAY_MENU:
    
    LEA DX, MAIN_MSG
    MOV AH, 09H
    INT 21H
 
    LEA DX, OPT_1
    MOV AH, 09H
    INT 21H
    
    LEA DX, OPT_2
    MOV AH, 09H
    INT 21H
    
    LEA DX, OPT_3
    MOV AH, 09H
    INT 21H
    
    LEA DX, OPT_4
    MOV AH, 09H
    INT 21H
       
    ;USER INPUT
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;CHECK
    
    CMP AL, '1'
    JE  EMPLOYEE_MANAGEMENT
    
    CMP AL, '2'
    JE PAYROLL_MANAGEMENT
    
    CMP AL, '3'
    JE REPORTS_MENU
    
    CMP AL, '4'
    JE EXIT_PROGRAM
    
    LEA DX, INVALID
    MOV AH, 09H
    INT 21H    
    JMP DISPLAY_MENU    
    
EMPLOYEE_MANAGEMENT:
    
    LEA DX, EMP_MENU_MSG
    MOV AH, 09H
    INT 21H
    
    LEA DX, EMP_ADD
    MOV AH, 09H
    INT 21H
    
    LEA DX, EMP_EDIT
    MOV AH, 09H
    INT 21H
    
    LEA DX, EMP_VIEW
    MOV AH, 09H
    INT 21H
    
    LEA DX,  EMP_DEL
    MOV AH, 09H
    INT 21H
    
    LEA DX, EMP_BACK 
    MOV AH, 09H
    INT 21H
    
    ;USER INPUT
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;CHECK
    
    ;CMP AL, '1'
    ;JE  EMP_ADD
    
    ;CMP AL, '2'
    ;JE EMP_EDIT
    
    ;CMP AL, '3'
    ;JE EMP_VIEW
    
    ;CMP AL, '4'
    ;JE EMP_DELETE
    
    CMP AL, '5'
    JE DISPLAY_MENU
    
    LEA DX, INVALID
    MOV AH, 09H
    INT 21H    
    JMP EMPLOYEE_MANAGEMENT
    
PAYROLL_MANAGEMENT:
    
    LEA DX, P_MENU_MSG
    MOV AH, 09H
    INT 21H
    
    LEA DX, P_CALC
    MOV AH, 09H
    INT 21H
    
    LEA DX, P_SLIP
    MOV AH, 09H
    INT 21H
    
    LEA DX, P_SRCH
    MOV AH, 09H
    INT 21H
    
    LEA DX, P_BACK
    MOV AH, 09H
    INT 21H
    
    ;USER INPUT
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;CHECK
    
    ;CMP AL, '1'
    ;JE  P_CALC
    
    ;CMP AL, '2'
    ;JE P_SLIP
    
    ;CMP AL, '3'
    ;JE P_SRCH
    
    CMP AL, '4'
    JE DISPLAY_MENU
    
    LEA DX, INVALID
    MOV AH, 09H
    INT 21H    
    JMP PAYROLL_MANAGEMENT
    
REPORTS_MENU:
            
    LEA DX,  R_MENU_MSG
    MOV AH, 09H
    INT 21H
    
    LEA DX, R_ALL
    MOV AH, 09H
    INT 21H
    
    LEA DX, R_SAL 
    MOV AH, 09H
    INT 21H
    
    LEA DX, R_DEPT
    MOV AH, 09H
    INT 21H
    
    LEA DX, R_BACK
    MOV AH, 09H
    INT 21H
    
    ;USER INPUT
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;CHECK
    
    ;CMP AL, '1'
    ;JE  R_ALL
    
    ;CMP AL, '2'
    ;JE R_SAL 
    
    ;CMP AL, '3'
    ;JE R_DEPT
    
    CMP AL, '4'
    JE DISPLAY_MENU
    
    LEA DX, INVALID
    MOV AH, 09H
    INT 21H    
    JMP REPORTS_MENU
    
EXIT_PROGRAM:
     MOV AH, 4CH 
     INT 21H
 
MAIN ENDP
END MAIN