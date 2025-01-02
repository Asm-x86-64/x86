.386
.model flat,c

.code

; Return : 0 Error (Division by zero)
; Return : 1 Success

; Computation *prod = a * b
; Computation *quo =  a / b
; Computation *rem =  a % b

intMulDiv	PROC
	PUSH EBP
	MOV  EBP,ESP
	PUSH EBX

	XOR EAX,EAX

	MOV  ECX,DWORD PTR[EBP + 8]
	MOV  EDX,DWORD PTR[EBP + 12]

	OR  EDX,EDX						;TO CHECK B IS ZERO
	JZ  InvalidDivisor

	IMUL EDX,ECX

	MOV  EBX,DWORD PTR[EBP + 16]    ; EBX = PROD
	MOV  DWORD PTR[EBX],EDX			; *PROD = A * B

	MOV  EAX,ECX
	CDQ
	IDIV DWORD PTR[EBP + 12]

	MOV  EBX, DWORD PTR[EBP + 20]	;  EBX  = QUO
	MOV  DWORD PTR[EBX],EAX			; *QUO  = A / B

	MOV  EBX, DWORD PTR[EBP + 24]	;  EBX  = REM
	MOV  DWORD PTR[EBX],EDX			; *REM  = A % B
	MOV  EAX,1

InvalidDivisor:
	POP  EBX
	LEAVE
	RET

intMulDiv	ENDP
END