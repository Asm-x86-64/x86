.386

.model flat

.data

intArray SWORD 0,0,0,0,1,3,9,-34,-56,7,8
;intArray SWORD 0,0,0,0,0,0,0,0

.code 

start	PROC

	MOV EBX, OFFSET intArray	;EBX = base adderss of array
	MOV ECX, LENGTHOF intArray  ;Setting ECX counter for the loop ECX = 11 which is length of array
	
L1:
	CMP WORD PTR[EBX],0		;Compares by subtracts the second operand from first operand
	JNZ		found			;Jump not equal to zero
	add EBX,2
	LOOP L1
	JMP		notFound

found:
	MOVSX EAX, WORD PTR[EBX]
	JMP quit

notFound:
	MOV EAX, 999999		;Some random value indicate whole array is zero
	JMP quit

quit:
	ret


start	ENDP

END		start