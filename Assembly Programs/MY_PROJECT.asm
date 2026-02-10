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
    
    ;--- ADD EMPLOYEE --- 
    
    EMP_ID   DB 0DH, 0AH, 'Enter Emplyee ID: $'
    EMP_NAME DB 0DH, 0AH, 'Enter Name: $'
    EMP_SAL  DB 0DH, 0AH, 'Enter Basic Salary: $'
    SUCCESS  DB 0DH, 0AH, 'Employee Added Successfully!$', 0DH,0AH,'$'
    
    EMP_MSG_FULL DB 0DH, 0AH, 'Storage Full! Cannot add more.$'
    
    ;--- ARRAYS ---
    
    MAX_RECORDS  EQU 10 ; CONSTANT
    RECORD_COUNT DB  0
        
    EMP_IDS      DB 10 DUP(6  DUP('$'))
    EMP_NAMES    DB 10 DUP(21 DUP('$'))
    EMP_SALARIES DB 10 DUP(8  DUP('$'))
        
    ;--- DATA BUFFERS ---
    ;--- FORMAT: [MAX LENGTH , ACTUAL LENGTH , DATA SPACE] ---
       
    ID_IN   DB 6,0,6   DUP ('$')    
    NAME_IN DB 21,0,21 DUP ('$')    
    SAL_IN  DB 8,0,8   DUP ('$')    
    
    ;--- EDIT EMPLOYEE---
    
    EDIT_EMP_MSG DB 0DH, 0AH, '--- Editing Current Record ---$', 0DH, 0AH, '$'
    SUCCESS_EDIT DB 0DH, 0AH, 'Employee Edit Successfully!$'   , 0DH, 0AH, '$'
    
    ;--- VIEW EMPLOYEE ---
    
    VIEW_EMP_ID   DB 0DH, 0AH, 'ID OF EMPLOYEE: $'
    VIEW_EMP_NAME DB 0DH, 0AH, 'NAME OF EMPLOYEE: $'
    VIEW_EMP_SAL  DB 0DH, 0AH, 'SALARY OF EMPLOYEE: $'
    
    ;--- DELETE EMPLOYEE ---
    
    DEL_EMP_MSG DB 0DH, 0AH, 'RECORD DELETED SUCCESSFULLY!$', 0DH, 0AH, '$'
    INVALID_REC     DB 0DH, 0AH, 'RECORD NOT FOUND!$'
            
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
    
    ;---------------- MENU PRINT ------------------------------- 
    
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
       
    ;---------------- USER INPUT -----------------------------
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;----------------- CHECKING INPUT ------------------------
    
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
    
    ;---------------------- EMPLOYEE_MANAGEMENT -------------------------
    
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
    
    ;------------------- USER INPUT -----------------------------------
    
    LEA DX, CHOICE
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ;-------------------CHECKING INPUT --------------------------------
    
    CMP AL, '1'
    JE ADD_EMP_SECTION
    
    CMP AL, '2'
    JE EDIT_EMP_SECTION
    
    CMP AL, '3'
    JE VIEW_EMP_SECTION
    
    CMP AL, '4'
    JE DELETE_EMP_SECTION
    
    CMP AL, '5'
    JE DISPLAY_MENU
    
    LEA DX, INVALID
    MOV AH, 09H
    INT 21H    
    JMP EMPLOYEE_MANAGEMENT
    
    ;----------------------- ADDING EMPLOYEE ---------------------------
    
ADD_EMP_SECTION:
    
    ;----------------------- CHECK STORAGE -----------------------------
    
    MOV AL, RECORD_COUNT
    CMP AL, MAX_RECORDS
    JGE FULL_ERROR
    
    ;----------------------- ID INPUT ----------------------------------
    
    LEA DX, EMP_ID
    MOV AH, 09H
    INT 21H
    
    LEA DX, ID_IN
    MOV AH, 0AH
    INT 21H
    
    ;------------------------ CALCULATE OFFSET --------------------------
    
    MOV AL, RECORD_COUNT
    MOV BL, 6
    MUL BL
    
    LEA DI, EMP_IDS
    ADD DI, AX
    LEA SI, ID_IN + 2
    MOV CL, ID_IN[1]
    MOV CH, 0
    REP MOVSB
    
    ;----------------------- NAME INPUT ---------------------------------- 
    LEA DX, EMP_NAME
    MOV AH, 09H
    INT 21H
    
    LEA DX, NAME_IN
    MOV AH, 0AH
    INT 21H
    
    ;------------------------ CALCULATE OFFSET --------------------------
    
    MOV AL, RECORD_COUNT
    MOV BL, 21
    MUL BL
    
    LEA DI, EMP_NAMES
    ADD DI, AX
    LEA SI, NAME_IN + 2
    MOV CL, NAME_IN[1]
    MOV CH, 0
    REP MOVSB
    
    ;----------------------- SALARY INPUT ----------------------------------
    LEA DX, EMP_SAL
    MOV AH, 09H
    INT 21H
    
    LEA DX, SAL_IN
    MOV AH, 0AH
    INT 21H
    
    ;------------------------ CALCULATE OFFSET --------------------------
    
    MOV AL, RECORD_COUNT
    MOV BL, 8
    MUL BL
    
    LEA DI, EMP_SALARIES
    ADD DI, AX
    LEA SI, SAL_IN + 2
    MOV CL, SAL_IN[1]
    MOV CH, 0
    REP MOVSB
    
    ;----------------------- SUCCESS ---------------------------------
    
    INC RECORD_COUNT
    LEA DX, SUCCESS
    MOV AH, 09H
    INT 21H
    
    JMP EMPLOYEE_MANAGEMENT
    
    ;----------------------- STORAGE FULL MESSAGE --------------------
    
FULL_ERROR:
    
    LEA DX, EMP_MSG_FULL
    MOV AH, 09H
    INT 21H
    JMP DISPLAY_MENU
    
    ;----------------------- EDITING EMPLOYEE ---------------------------
     
EDIT_EMP_SECTION:
    
    LEA DX, EDIT_EMP_MSG
    MOV AH, 09H
    INT 21H
    
    LEA DX, VIEW_EMP_ID
    MOV AH, 09H 
    INT 21H
    
    LEA DX, ID_IN
    MOV AH, 0AH
    INT 21H
    
    LEA DX, VIEW_EMP_NAME
    MOV AH, 09H
    INT 21H
    
    LEA DX, NAME_IN
    MOV AH, 0AH
    INT 21H
    
    LEA DX, VIEW_EMP_SAL
    MOV AH, 09H
    INT 21H
    
    LEA DX, SAL_IN
    MOV AH, 0AH
    INT 21H
    
    LEA DX, SUCCESS_EDIT
    MOV AH, 09H
    INT 21H
    
    JMP EMPLOYEE_MANAGEMENT
    
    ;----------------------- VIEW EMPLOYEE ---------------------------
      
VIEW_EMP_SECTION:
    
    ;CMP NAME_IN[1], 0
    ;JE RECORD_NOT_FOUND
    
    CMP RECORD_COUNT, 0
    JE  NO_RECORDS
    
    MOV CL, RECORD_COUNT
    MOV CH, 0
    MOV SI, 0
    
PRINT_LOOP:
    
    PUSH CX
    
    ;----------------------- PRINT ID -------------------------------
    
    LEA DX, VIEW_EMP_ID
    MOV AH, 09H
    INT 21H
    
    MOV AX, SI
    MOV BX, 6
    MUL BX
    
    LEA DX, EMP_IDS
    ADD DX, AX
    MOV AH, 09H
    INT 21H
    
    ;LEA DX, ID_IN+2
    ;MOV AH, 09H
    ;INT 21H
    
    ;----------------------- PRINT NAME -------------------------------
    
    LEA DX, VIEW_EMP_NAME
    MOV AH, 09H
    INT 21H
    
    MOV AX, SI
    MOV BX, 21
    MUL BX
    
    LEA DX, EMP_NAMES
    ADD DX, AX
    MOV AH, 09H
    INT 21H
    
    ;LEA DX, NAME_IN+2
    ;MOV AH, 09H
    ;INT 21H
    
    ;----------------------- PRINT SALARY -------------------------------
    
    LEA DX, VIEW_EMP_SAL
    MOV AH, 09H
    INT 21H
    
    MOV AX, SI
    MOV BX, 8
    MUL BX
    
    LEA DX, EMP_SALARIES
    ADD DX, AX
    MOV AH, 09H
    INT 21H
    
    ;LEA DX, SAL_IN+2
    ;MOV AH, 09H
    ;INT 21H
    
    ;----------------------- NEXT RECORD ----------------------------
    INC SI
    POP CX
    
    LOOP PRINT_LOOP
    
    JMP VIEW_EXIT
    
NO_RECORDS:

    LEA DX, INVALID_REC
    MOV AH, 09H
    INT 21H
    
VIEW_EXIT:
    
    MOV AH, 01H
    INT 21H
    JMP EMPLOYEE_MANAGEMENT
    
    ;----------------------- DELETING EMPLOYEE --------------------------- 
    
DELETE_EMP_SECTION:
    
    MOV ID_IN[1], 0
    LEA DI, ID_IN+2
    MOV CX, 5
    MOV AL, '$'
    REP STOSB
    
    MOV NAME_IN[1], 0
    LEA DI, NAME_IN+2
    MOV CX, 20
    MOV AL, '$'
    REP STOSB
    
    MOV SAL_IN[1], 0
    LEA DI, SAL_IN+2
    MOV CX, 7
    MOV AL, '$'
    REP STOSB
        
    LEA DX, DEL_EMP_MSG
    MOV AH, 09H
    INT 21H
    
    JMP EMPLOYEE_MANAGEMENT 

    ;----------------------- PAYROLL_MANAGEMENT --------------------------- 
               
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
    
    ;----------------------- REPORTS_MANAGEMENT ---------------------------
    
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