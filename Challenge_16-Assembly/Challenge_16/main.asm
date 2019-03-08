    .global  main                                   ; makes main accessible from outside this file.
    .thumb                                          ; use thumb
    .data                                           ; set memory location to sram
    ; put your variables here
    .text                                           ; set memory location to flash
y .FIELD  700 ;value of y
x .FIELD  500 ;value of x

main:
	ldr  R0, y ;load value of y in R0
	ldr  R1, x ;load value of x in R1

LOOP: ;while loop
	cbz  R0, END ; check if y not equal zero
	ldr  R1, x ; load value of x again
	mov  R1, R1, lsr #1 ; divide x by 2
	cmp r0,r1 ; compare value of x to y
	blt ELSE ; goto branch else
	bEQ  ELSE ; goto branch else
	b  IF ;goto branch if

ELSE: ;branch else
	sub R0, #100 ; subtract y -100
	b LOOP ; goto branch loop again

IF: ; branch if
	ldr  R1, x ; load value of x in R1 again
	mov  R1, R1, lsr #1 ; divide by 2
	sub R0, R0,R1 ; subtract y - x/2
	b  LOOP ;goto branch loop

END:
