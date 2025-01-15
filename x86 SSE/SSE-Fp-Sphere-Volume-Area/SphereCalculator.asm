.model flat,c

; SSE SCALAR INSTRUCTIONS

.const
	r8_pi		REAL8	3.14159265358979323846
	r8_four		REAL8	4.0
	r8_three	REAL8	3.0
	r8_neg_one	REAL8  -1.0


.code

SSESphereCalculator	PROC
	
		;PROLOUGE
		PUSH EBP
		MOV EBP,ESP

		XOR EAX,EAX

		MOVSD XMM0,QWORD PTR[EBP + 8]

		MOV  ECX,DWORD PTR[EBP + 16]
		MOV  EDX,DWORD PTR[EBP + 20]

		XORPD XMM7,XMM7
		COMISD XMM0,XMM7
		
		JP BadRadius					; Undefined
		JB BadRadius

		;SURFACE AREA = 4pir^2
		MOVSD XMM1,XMM0
		MULSD XMM1,XMM1
		MULSD XMM1,r8_four
		MULSD XMM1,r8_pi

		MOVSD REAL8 PTR[ECX],XMM1

		;VOLUME	= 4pir^3/3
		MULSD XMM1,XMM0	
		DIVSD XMM1,r8_three

		MOVSD QWORD PTR[EDX],XMM1

		MOV EAX,1
		JMP return

BadRadius:
		MOVSD XMM0,r8_neg_one
		MOVSD REAL8 PTR[ECX],XMM0
		MOVSD REAL8 PTR[EDX],XMM0

return:
		LEAVE
		RET
		
SSESphereCalculator	ENDP

END