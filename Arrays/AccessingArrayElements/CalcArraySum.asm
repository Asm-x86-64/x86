.model flat,c

; @F -> Jumps Forward  to the nearest '@@' symbol
; @B -> Jumps Backword to the nearest '@@' symbol

.code
calculateSum	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	MOV EDX,DWORD PTR[EBP + 8]
	MOV ECX,DWORD PTR[EBP + 12]

	XOR EAX,EAX

	CMP ECX,0
	JLE InvalidIndex

@@:
	ADD EAX,DWORD PTR[EDX]
	ADD EDX,4
	DEC ECX
	JNZ @B						; @B -> Jumps Backword to the nearest '@@' symbol

InvalidIndex:
	;EPILOUGE
	LEAVE
	RET

calculateSum	ENDP

END