.386
.model flat

;Custom type definition
PBYTE TYPEDEF PTR BYTE
PWORD TYPEDEF PTR WORD
PDWORD TYPEDEF PTR DWORD

.data
	arrayB BYTE 10H,20H,30H
	arrayW WORD 1,2,3
	arrayD DWORD 4,5,6

;pointers doesn't require offset operator to fetch address
ptr1 PBYTE arrayB	;Byte pointer variable for arrayB 
ptr2 PWORD arrayW	;Word pointer variable for arrayW
ptr3 PDWORD arrayD	;Dword pointer variabe for arrayD


.code

start	PROC
		MOV ESI,ptr1
		MOV AL,[ESI]

		MOV ESI,ptr2
		MOV AX,[ESI]

		MOV ESI,ptr3
		MOV EAX,[ESI]

		ret

start	ENDP
END		start
