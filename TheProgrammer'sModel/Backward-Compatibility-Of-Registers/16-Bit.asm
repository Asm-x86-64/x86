;-------------------- 16-Bit 

;Accessing Lower 16-Bits of 32-Bit registers, this provides backward compatibility
;The upper 16-Bits might have any random values in this scenario

.386
.model flat
.code
main    PROC
        MOV AX, 2
        MOV BX, 3
        MOV CX, 4
        ret
main    endp
end