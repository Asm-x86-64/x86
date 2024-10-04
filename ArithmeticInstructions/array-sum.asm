.386
.model flat

.data 
	intArray DWORD 10000H, 20000H, 30000H, 40000H;

.code 

start PROC
	  MOV EDI,OFFSET intArray ; OFFSET OPERATOR IS USED TO EXTRACT ADDRESS OF THE VARIABLE
	  MOV ECX,LENGTHOF intArray
	  MOV EAX,0

LP:
	ADD EAX,[EDI]
	ADD EDI, TYPE intArray
	LOOP LP

	ret
start	ENDP
END		start