.model flat,c

.const
	r4_MinFloat		DWORD	0FF7FFFFFH
	r4_MaxFloat		DWORD	 7F7FFFFFH

.code

CalcMinMax	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	XOR EAX,EAX

	MOV EDX,DWORD PTR[EBP + 8]
	MOV ECX,DWORD PTR[EBP + 12]

	TEST ECX,ECX
	JLE  Done

	FLD  r4_MinFloat		;ST(0) = r4_MinFloat
	FLD  r4_MaxFloat		;ST(0) = r4_MaxFloat,ST(1) = r4_MinFloat

@@:
	FLD REAL4 PTR[EDX]		;ST(0) = *ARRAY,ST(1) = r4_MaxFloat,ST(2) = r4_MinFloat
	FLD ST(0)				;ST(0) = *ARRAY,ST(1) = *ARRAY,ST(2) = r4_MaxFloat,ST(3) = r4_MinFloat

	FCOMI	ST(0),ST(2)		
	FCMOVNB ST(0),ST(2)		;ST(0) = MIN(*ARRAY,r4_MaxFloat) 
	 
	FSTP ST(2)				; SAVE THE ST(0) IN ST(2)

	FCOMI ST(0),ST(2)		
	FCMOVB ST(0),ST(2)		; ST(0) = MAX(*ARRAY, r4_MinFloat)

	FSTP ST(2)				; SAVE THE ST(0) IN ST(2)

	ADD EDX,4
	DEC ECX
	JNZ @B

	MOV EAX,DWORD PTR[EBP + 16]
	FSTP REAL4 PTR[EAX]

	MOV EAX,DWORD PTR[EBP + 20]
	FSTP REAL4 PTR[EAX]

	MOV EAX,1

Done:
	LEAVE
	RET

CalcMinMax	ENDP
END