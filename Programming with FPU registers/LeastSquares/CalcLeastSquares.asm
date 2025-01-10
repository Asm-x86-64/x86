.model flat,c

;ACCESS CONTROL
PUBLIC LsEpsilon

.const
	LsEpsilon	REAL8	1.0E-12

.code
CalcLeastSquaresASM		PROC
	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	SUB  ESP,8		;LOCAL VARIABLE (DENOMINATOR)

	XOR  EAX,EAX	

	MOV ECX,DWORD PTR[EBP + 16]
	TEST ECX,ECX
	JLE  Done

	MOV EAX,DWORD PTR[EBP + 8]
	MOV EDX,DWORD PTR[EBP + 12]

	FLDZ							; SUM_XX
	FLDZ							; SUM_XY
	FLDZ							; SUM_Y
	FLDZ							; SUM_X

; FPU STACK -> ST(0) = SUM_X -> (0),ST(1) = SUM_Y -> (0),ST(2) = SUM_XY -> (0),ST(3) = SUM_XX -> (0)

@@:	
	FLD REAL8 PTR[EAX]
	FLD ST(0)
	FLD ST(0)
	FLD REAL8 PTR[EDX]

; FPU STACK -> FULL
; FPU STACK -> ST(0) = Y , ST(1) = X,ST(2) = X,ST(3) = X,ST(4) = SUM_X ,ST(5) = SUM_Y ,ST(6) = SUM_XY ,ST(7) = SUM_XX 

	FADD ST(5),ST(0)		;SUM_Y += Y
	FMULP					;ST(0) =ST(0) * ST(1) => X * Y

; FPU STACK -> ST(0) = XY ,ST(1) = X,ST(2) = X,ST(3) = SUM_X ,ST(4) = SUM_Y ,ST(5) = SUM_XY ,ST(6) = SUM_XX 

	FADDP ST(5),ST(0)		;SUM_XY += XY

; FPU STACK -> ST(0) = X,ST(1) = X,ST(2) = SUM_X ,ST(3) = SUM_Y ,ST(4) = SUM_XY ,ST(5) = SUM_XX 
	FADDP ST(2),ST(0)		;SUM_X += X

; FPU STACK -> ST(0) = X,ST(1) = SUM_X ,ST(2) = SUM_Y ,ST(3) = SUM_XY ,ST(4) = SUM_XX 
	FMUL ST(0),ST(0)
	FADDP ST(4),ST(0)		;SUM += XX

; FPU STACK -> ST(0) = SUM_X ,ST(1) = SUM_Y ,ST(2) = SUM_XY ,ST(3) = SUM_XX 
	ADD EAX,8
	ADD EDX,8
	DEC ECX
	JNZ @B

;    double denom = n * sum_xx - sum_x * sum_x;

	FILD DWORD PTR [EBP + 16]
; FPU STACK -> ST(0) = N,ST(1) = SUM_X ,ST(2) = SUM_Y ,ST(3) = SUM_XY ,ST(4) = SUM_XX 
	FMUL ST(0),ST(4)			; N * SUMXX
; FPU STACK -> ST(0) = N*SUM_XX ,ST(1) = SUM_X ,ST(2) = SUM_Y ,ST(3) = SUM_XY ,ST(4) = SUM_XX 

	FLD ST(1)					; SUM_X
; FPU STACK ->ST(0) = SUM_X , ST(1) = N*SUM_XX ,ST(2) = SUM_X ,ST(3) = SUM_Y ,ST(4) = SUM_XY ,ST(5) = SUM_XX 
	FLD ST(0)					; SUM_X
; FPU STACK ->ST(0) = SUM_X,ST(1) = SUM_X , ST(2) = N*SUM_XX ,ST(3) = SUM_X ,ST(4) = SUM_Y ,ST(5) = SUM_XY ,ST(6) = SUM_XX 

	FMULP
; FPU STACK ->ST(0) = SUM_X*SUM_X , ST(1) = N*SUM_XX ,ST(2) = SUM_X ,ST(3) = SUM_Y ,ST(4) = SUM_XY ,ST(5) = SUM_XX 

	FSUBP
; FPU STACK ->ST(0) =N*SUM_XX - SUM_X*SUM_X ,ST(1) = SUM_X ,ST(2) = SUM_Y ,ST(3) = SUM_XY ,ST(4) = SUM_XX 

	FST REAL8 PTR[EBP - 8]

; FPU STACK :- DENOM, SUM_X , SUM_Y , SUM_XY, SUM_XX
	FABS						;FABS(ST(0)) FABS(DENOM)

	FLD		LsEpsilon
	FCOMIP	ST(0),ST(1)
	FSTP st(0)
; FPU STACK :-  SUM_X , SUM_Y , SUM_XY, SUM_XX
	JAE     InvalidDone



; *m = (n*sum_xy - sum_x * sum_y) / denom

	FILD DWORD PTR[EBP + 16]

; FPU STACK :-N, SUM_X , SUM_Y , SUM_XY, SUM_XX


	FMUL ST(0),ST(3)		; N * SUM_XY
; FPU STACK :-N*SUM_XY, SUM_X , SUM_Y , SUM_XY, SUM_XX
	FLD  ST(2)				; SUM_Y

; FPU STACK :-SUM_Y ,N*SUM_XY,SUM_X , SUM_Y , SUM_XY, SUM_XX
	FLD ST(2)				; SUM_X

; FPU STACK :-SUM_X,SUM_Y ,N*SUM_XY, SUM_X , SUM_Y , SUM_XY, SUM_XX
	FMULP
; FPU STACK :-SUM_X*SUM_Y ,N*SUM_XY, SUM_X , SUM_Y , SUM_XY, SUM_XX
	FSUBP
; FPU STACK :-N*SUM_XY - SUM_X*SUM_Y , SUM_X , SUM_Y , SUM_XY, SUM_XX
	FDIV REAL8 PTR[EBP - 8]

	MOV EAX,DWORD PTR[EBP +  20]
	FSTP REAL8 PTR[EAX]


;*b = (sum_xx * sum_y - sum_x * sum_xy) / denom;

; FPU STACK :- SUM_X , SUM_Y , SUM_XY, SUM_XX

	FXCH ST(3)
; FPU STACK :-SUM_XX , SUM_Y ,SUM_XY  , SUM_X

	FMULP
; FPU STACK :- SUM_XX * SUM_Y ,SUM_XY  , SUM_X

	FXCH ST(2)
; FPU STACK :- SUM_X, SUM_XY, SUM_XX * SUM_Y 

	FMULP
; FPU STACK :- SUM_X * SUM_XY, SUM_XX * SUM_Y 

	FSUBP 
; FPU STACK :-SUM_XX * SUM_Y  - SUM_XY * SUM_X

	FDIV REAL8 PTR[EBP - 8]

	MOV EAX,DWORD PTR[EBP + 24]
	FSTP REAL8 PTR[EAX]

	MOV EAX,1

Done:
	;EPILOUGE
	LEAVE
	RET

InvalidDone:
	FSTP ST(0)
	FSTP ST(0)
	FSTP ST(0)
	FSTP ST(0)
	JMP Done


CalcLeastSquaresASM		ENDP
END