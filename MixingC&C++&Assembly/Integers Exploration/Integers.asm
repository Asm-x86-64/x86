.386
.model flat, c

EXTERN GLCHAR : BYTE;
EXTERN GLSHORT : WORD;
EXTERN GLINT : DWORD;
EXTERN GLONG : QWORD;


.code
IntegerAddition	PROC
	; PROLOGUE
	PUSH EBP
	MOV  EBP, ESP

	; Compute GLCHAR += a
	MOV AL, BYTE PTR[EBP + 8]
	ADD BYTE PTR[GLCHAR], AL

	; Compute GLSHORT += b
	MOV AX, WORD PTR[EBP + 12]
	ADD WORD PTR[GLSHORT], AX

	; Compute GLINT += c
	MOV EAX, DWORD PTR[EBP + 16]
	ADD DWORD PTR[GLINT], EAX

	; Compute GLLONG += d
	MOV EAX, DWORD PTR[EBP + 20]; LOWER  32 - BITS
	MOV EDX, DWORD PTR[EBP + 24]; HIGHER 32 - BITS
	ADD DWORD PTR[GLONG],EAX    ; GLONG lower bits + input value lower bits
	ADC DWORD PTR[GLONG + 4],EDX ; GLONG higher bits + input value higher bits + carry from sum of lower 32 bits and input value lower bits

	LEAVE
	RET


IntegerAddition	ENDP
END