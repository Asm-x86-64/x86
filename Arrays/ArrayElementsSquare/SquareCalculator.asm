.model flat,c


.code 

CalcArraySquares	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP
	PUSH EBX
	PUSH ESI
	PUSH EDI


	MOV  EDI,DWORD PTR[EBP + 8]
	MOV  ESI,DWORD PTR[EBP + 12]
	MOV  ECX,DWORD PTR[EBP + 16]

	XOR  EAX,EAX
	
	CMP  ECX,0
	JLE  InvalidIndex
	SHL  ECX,2

	XOR  EBX,EBX

@@:
	MOV  EDX,DWORD PTR[ESI + EBX]
	IMUL EDX,EDX
	MOV  DWORD PTR[EDI + EBX],EDX
	ADD  EAX,EDX
	ADD  EBX,4
	CMP  EBX,ECX
	JL   @B

InvalidIndex:
	;EPILOUGE
	POP  EDI
	POP  ESI
	POP  EBX
	LEAVE
	RET


CalcArraySquares	ENDP

END