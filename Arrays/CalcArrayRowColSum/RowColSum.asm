.model flat,c


.code
CalcArrayRowColSum	PROC
	;PROLOGUE
	PUSH EBP
	MOV  EBP,ESP
	PUSH EBX
	PUSH ESI
	PUSH EDI


	CMP DWORD PTR[EBP + 12],0					;NROWS == 0
	JLE InvalidArg

	MOV ECX,DWORD PTR[EBP + 16]					;ECX = NCOLS 
	CMP ECX,0
	JLE InvalidArg

	;Initialize the cols_sum elements to zero
	MOV EDI,DWORD PTR[EBP + 24]					;EDI = &COLS_SUM[0]
	XOR EAX,EAX									;EAX = 0
	REP STOSD									;FILL ARRAY WITH ZEROS

	MOV EBX,DWORD PTR[EBP + 8]					;EBX = &X[0]
	XOR ESI,ESI									;ESI -> (I) = 0 


LP1:
	;OUTER LOOP
	MOV EDI,DWORD PTR[EBP + 20]					;EDI = &ROWS_SUM[0]
	MOV DWORD PTR[EDI + ESI * 4],0				;ROWS_SUM[I] = 0
	XOR EDI,EDI									;EDI -> (J) = 0
	MOV EDX,ESI									;EDX = I
	IMUL EDX,DWORD PTR[EBP + 16]				;I * NCOLS

LP2:
	;INNER LOOP
	MOV ECX,EDX									;ECX = I * NCOLS
	ADD ECX,EDI									;ECX = I * NCOLS + J
	MOV EAX,DWORD PTR[EBX + ECX * 4]
	MOV ECX,DWORD PTR[EBP + 20]					;ECX = &ROWS_SUM[0]
	ADD DWORD PTR[ECX + ESI * 4],EAX			;ROWS_SUM[I] += EAX
	MOV ECX,DWORD PTR[EBP + 24]					;ECX = &COLS_SUM[0]
	ADD DWORD PTR[ECX + EDI * 4],EAX			;COLS_SUM[J] += EAX


	INC EDI										;J++
	CMP EDI,DWORD PTR[EBP + 16]					;J < NCOLS
	JL  LP2

	INC ESI										;I++
	CMP ESI,DWORD PTR[EBP + 12]					;I < NROWS
	JL  LP1

	MOV EAX,1									;RETURN SUCCESS

InvalidArg:
	;EPILOUGE
	POP EDI
	POP ESI
	POP EBX
	LEAVE
	RET




CalcArrayRowColSum	ENDP
END