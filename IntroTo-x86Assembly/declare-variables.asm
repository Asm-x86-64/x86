.386
.model flat

.data
num1 DWORD 11111111H
num2 DWORD 10101010H
res	 DWORD 00000000H

.code
main	PROC
		MOV EAX,num1;
		ADD EAX,num2;
		MOV res,EAX;
		ret
main	ENDP
END		main
