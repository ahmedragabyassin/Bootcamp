/*
 * Interrupts.c
 *
 * Created: 2/21/2019 12:05:39 AM
 *  Author: Ahmed Yassin
 */ 

#include "../Includes/Interrupts.h"
volatile uint64 Gtick = NUM_0; /* hold the number of interrupts to compare with required delay */
volatile uint8 int2   = NUM_0;  /* flag to detect if INT2 occurred */

/************************************************************************/
/* Function: Interrupts Init                                            */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Init interrupts                                         */
/************************************************************************/
void Interrupts_init(void)
{
		SET_BIT(GICR,INT2); /* enable interrupt 2 */
		sei(); /* enable global interrupt */
}


/************************************************************************/
/* Interrupt to handle if button pressed                                */
/************************************************************************/
ISR(INT2_vect)
{
	int2++;
}

/************************************************************************/
/* Interrupt to handle when compare match occur                        */
/************************************************************************/
ISR(TIMER0_COMP_vect)
{
	Gtick++;
}



