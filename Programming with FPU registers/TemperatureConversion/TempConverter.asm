.model flat,c

.const 
	
	r8_SfFtoC	REAL8 0.5555555555555556 ; 5 / 9
	r8_SfCtoF	REAL8 1.8				 ; 9 / 5
	i4_32		DWORD 32

.code 

; F TO C : Deduct 32, then multiply by 5, then divide by 9
FarenheitToCelsius	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	FLD r8_SfFtoC				; Push | Load Constant into FPU stack 
	FLD REAL8 PTR[EBP + 8]		; Push | Load Constant into FPU stack 
	FILD i4_32					; Push | Load double precision converted integer constant into FPU stack 

	FSUBP						; ST(0) = ST(1) - ST(0) POP the stack top
	FMULP						; ST(0) = ST(1) * ST(0) POP the stack top

	;EPILOUGE
	LEAVE
	RET
FarenheitToCelsius	ENDP

; C to F : Multiply by 9, then divide by 5 and then add 32
CelsiusToFarenheit	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	FLD REAL8 PTR[EBP + 8]		; Push | Load Constant into FPU stack 
	FLD r8_SfCtoF				; Push | Load Constant into FPU stack 
	FILD i4_32					; Push | Load Constant into FPU stack 

	FMULP						; ST(0) = r8_SfCtoF * ST(0) POP the stack top
	FADDP						; ST(0) = i4_32 + ST(0) POP the stack top

	;EPILOUGE
	LEAVE
	RET


CelsiusToFarenheit	ENDP
END