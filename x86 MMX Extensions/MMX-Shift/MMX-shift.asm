.model flat,c

.code

MMXShift	PROC
	;PROLOUGE
	PUSH EBP
	MOV EBP,ESP

	XOR EAX,EAX

	MOV EDX,DWORD PTR[EBP + 16]
	CMP EDX,ShiftOpTableCount
	JAE BadShiftOp

	MOV EAX,1

	MOVQ MM0,QWORD PTR[EBP + 8]
	MOVD MM1,DWORD PTR[EBP + 20]
	JMP  [ShiftOpTable + EDX * 4]

MmxPsllw:
	PSLLW MM0,MM1					;SHIFT LEFT LOGICAL WORD
	JMP SaveREsult

MmxPsrlw:
	PSRLW MM0,MM1
	JMP SaveResult					;SHIFT RIGHT LOGICAL WORD

MmxPsraw:
	PSRAW MM0,MM1					;SHIFT RIGHT ARITHMETIC WORD
	JMP SaveResult

MmxPslld:
	PSLLD MM0,MM1					;SHIFT LEFT LOGICAL WORD
	JMP SaveResult

MmxPsrld:
	PSRLD MM0,MM1					;SHIFT RIGHT LOGICAL DWORD
	JMP SaveResult

MmxPsrad:
	PSRAD MM0,MM1					;SHIFT RIGHT ARITHMETIC DWORD
	JMP SaveResult

BadShiftOp:
	PXOR MM0,MM0

SaveResult:
	MOV EDX,DWORD PTR[EBP + 24]
	MOVQ QWORD PTR[EDX],MM0
	EMMS

	;EPILOUGE
	LEAVE
	RET


; JUMP TABLE
ShiftOpTable:
			DWORD MmxPsllw,MmxPsrlw,MmxPsraw
			DWORD MmxPslld,MmxPsrld,MmxPsrad

ShiftOpTableCount EQU ($ - ShiftOpTable) / SIZE DWORD

MMXShift	ENDP
END