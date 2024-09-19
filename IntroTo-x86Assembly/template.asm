;This program adds and subtracts 32-Bit integers

.386 ; .386  directive identifies the minimum CPU required for this program, in this case it is intel 386 first x86 processor 

;.model directive is used for two purposes it identifies segemntation model and it also identifies the convention
;use for passing parameters to procedure in the dot model directive
;In the dot model directie, the flat keyword tells the assembler to generate code for protected mode programs
;stdcall keyword enables the calling off MS windows functions.
.model flat,stdcall 

.stack 4096

.code   ;The code segment where all executable statements in a program are located.
main    PROC ;The PROC directive identifies begining of the procedure

        ;SYNTAX:- MOV <DEST>,<SRC> 
        ;SYNTAX:- ADD <DEST>,<SRC> | DEST_VAL = DEST_VAL + SRC_VAL
        ;SYNTAX:- SUB <DEST>,<SRC> | DEST_VAL = DEST_VAL - SRC_VAL

        MOV eax,10000h  ;EAX = 10000H
        ADD eax,40000h  ;EAX = 50000H
        SUB eax,20000h  ;EAX = 30000H
        ret
main ENDP   ;The ENDP marks the end of the main procedure
END main    
;The END directive marks the last line of the program to be assembled it identifies the name of the programs start up procedure and this is basically the procedure 
;starts the program