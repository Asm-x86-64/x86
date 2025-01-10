.model flat, c

;Surface Area of a sphere : 4pir^2
;Volume of a sphere : 4pir^3/3


.const
	r8_4p0    REAL8		4.0
	r8_3p0	  REAL8		3.0


.code

CalcSphereAreaVolume	PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	XOR EAX,EAX

	FLD  REAL8  PTR[EBP + 8] ; ST(0) = RADIUS
	FLDZ					 ; ST(0) = 0.0  ST(1) = RADIUS
	FCOMIP  ST(0),ST(1)		 ; COMPARES 0.0 TO REDIUS AND POP ST(0)


	JAE DONE                 ; JUMP IF ST(0) >= ST(1)

	FLD  REAL8 PTR[EBP + 8]	; ST(0) = RADIUS, ST(1) = RADIUS

	FMUL ST(0),ST(0)		; ST(0) = RADIUS^2 , ST(1) = RADIUS

	FLDPI					; ST(0) = PI , ST(1) = RADIUS^2 , ST(2) = RADIUS

	FMUL [r8_4p0]			; ST(0) = 4 * PI , ST(1) = RADIUS^2 , ST(2) = RADIUS
	FMULP					; ST(0) = 4 * PI * RADIUS^2, ST(1) = RADIUS

	MOV EDX,[EBP + 16]		; EDX = SURFACE_AREA
	FST REAL8 PTR[EDX]		; *SURFACE_AREA = ST(0)

	FMULP					; ST(0) = 4 * PI * RADIUS^3, ST(1) = RADIUS
	FDIV [r8_3p0]			; ST(0) =  4 * PI * RADIUS^3/3 , ST(1) = RADIUS

	MOV EDX,[EBP+20]		; EDX = VOLUME
	FSTP REAL8 PTR[EDX]		; *VOLUME = ST(0)

	MOV EAX,1				; SUCCESS

Done:
	;EPILOUGE
	LEAVE 
	RET

CalcSphereAreaVolume	ENDP
END