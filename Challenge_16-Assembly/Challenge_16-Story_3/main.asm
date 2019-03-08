    .global  main                                   ; makes main accessible from outside this file.
    .thumb                                          ; use thumb
    .data                                           ; set memory location to sram
    ; put your variables here
    .text                                           ; set memory location to flash

address .FIELD  0x20000400 ;define address in memory to access

main:
	LDR r0,address ; store address in R0
	MOV r5, #1 ;store 1 in R5
	MOV r6, #2 ;store 2 in R6
	MOV r7, #3 ;store 3 in R7
	MOV r8, #4 ;store 4 in R8
	MOV r9, #5 ;store 5 in R9

	STM r0,{r5-r9} ; Store in memory start from address in R0 and increment after
End:



