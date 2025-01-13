.model flat,c

.code

MmxAdd		PROC

	;PROLOUGE
	PUSH EBP
	MOV  EBP,ESP

	MOV EAX,[EBP + 24]			; ADD_OP
	CMP EAX,AddOpTableCount		
	JAE BadAddOp

	MOVQ MM0,QWORD PTR[EBP + 8]
	MOVQ MM1,QWORD PTR[EBP + 16]

	;Jump to calculated switch case
	JMP  [AddOpTable + eax * 4]


MmxPaddb:
	PADDB MM0,MM1				; Packed Byte Addition Using Wraparound
	JMP   SaveResult

MmxPaddsb:
	PADDSB MM0,MM1				; Packed Byte Addition Using Signed Saturation
	JMP   SaveResult

MmxPaddusb:
	PADDUSB MM0,MM1				; Packed Byte Addition Using Unsigned Saturation
	JMP   SaveResult

MmxPaddw:
	PADDW MM0,MM1				; Packed Word Addtion Using WrapAround
	JMP	  SaveResult

MmxPaddsw:
	PADDSW MM0,MM1				; Packwd Word Addition Using Signed Saturation
	JMP	   SaveResult

MmxPaddusw:
	PADDUSW MM0,MM1				; Packed Word Addition Using Unsigned Saturation
	JMP    SaveResult

MmxPaddd:
	PADDD MM0,MM1				; Packed Dword Addition Using Unsigned Saturation
	JMP    SaveResult

BadAddOp:
	PXOR MM0,MM0


SaveResult:
	; IN __cdecl calling convention the function follows EDX:EAX to return 64-Bit values.
	; EDX:EAX   -> UPPER 32-BITS : LOWER 32-BITS

	MOVD EAX,MM0				; EAX CONTAINS LOWER 32-BITS
	PSHUFW MM2,MM0, 01001110B   ; SHUFFLE LOWER WORDS AND UPPER WORDS
	MOVD EDX,MM2				; EDX CONTAINS UPPER 32-BITS
	EMMS						; CLEAR MMX STATE AND RESTORE THE FPU REGISTERS

	;EPILOUGE
	LEAVE
	RET


; JUMP TABLE
AddOpTable:
	DWORD MmxPaddb,MmxPaddsb,MmxPaddusb
	DWORD MmxPaddw,MmxPaddsw,MmxPaddusw,MmxPaddd

AddOpTableCount	EQU ($ - AddOpTable)/ SIZE DWORD



MmxAdd		ENDP
END
