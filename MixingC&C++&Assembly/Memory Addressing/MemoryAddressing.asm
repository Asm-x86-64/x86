.386
.model flat, c

PUBLIC NumFibVals

.const 

    ; int FibVals[] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610}
    FibVals DWORD 0,1,1,2,3,5,8,13,21
            DWORD 34,55,89,144,233,377,610

   
    ;NumFibVals = sizeof(NumFibVals)/sizeof(dword)
    NumFibVals DWORD ($ - FibVals) / SIZEOF(DWORD)

    

.code

MemoryAddress   PROC
    ;PROLOGUE
    PUSH EBP
    MOV  EBP,ESP
    PUSH EBX
    PUSH ESI
    PUSH EDI

    XOR  EAX,EAX
    MOV  ECX,DWORD PTR[EBP + 8]
    CMP  ECX,0
    JL   InvalidIndex
    CMP  ECX,NumFibVals
    JGE  InvalidIndex

    ; Examples of Different ways of Memory addressing

    ; Eg1:- Base register
    MOV EBX,OFFSET FibVals
    MOV ESI,DWORD PTR[EBP + 8]
    SHL ESI,2               ; SHIFT LEFT BY 2-BITS WHICH IS ALSO EQUIVALENT TO ESI * 2^2
    ADD EBX,ESI
    MOV EAX,[EBX]
    MOV EDI,DWORD PTR[EBP + 12]
    MOV DWORD PTR[EDI],EAX

    ; Eg2:- Base register + displacement
    MOV ESI,DWORD PTR[EBP + 8]
    SHL ESI,2
    MOV EAX,[FibVals + ESI]    ; Base Address + OFFSET
    MOV EDI,DWORD PTR[EBP + 16]
    MOV DWORD PTR[EDI],EAX

    ; Eg3:- Base register + Index register
    MOV EBX,OFFSET FibVals
    MOV ESI,DWORD PTR[EBP + 8]
    SHL ESI,2
    MOV EAX, DWORD PTR[EBX + ESI] ; Base Address + index register

    MOV EDI,DWORD PTR[EBP + 20]
    MOV DWORD PTR[EDI],EAX

    ; Eg4:- Base register + Index register * scale factor
    MOV EBX,OFFSET FibVals
    MOV ESI,DWORD PTR[EBP + 8]
    MOV EAX,DWORD PTR[EBX + ESI * 4] ; Base register + index register * scale factor
    MOV EDI,DWORD PTR[EBP + 24]
    MOV DWORD PTR[EDI],EAX
    MOV EAX,1

InvalidIndex:
    ;EPILOGUE
    POP EDI
    POP ESI
    POP EBX
    LEAVE
    RET

MemoryAddress   ENDP
END
