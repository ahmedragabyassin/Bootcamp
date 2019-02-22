/*
 * Timer.c
 *
 * Created: 2/13/2019 8:58:21 PM
 *  Author: Ahmed Yassin
 */ 

#include "../Includes//Timer.h"
#include "../Includes/TimerMemMap.h"

/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerInit(void)
{
	/************************************************************************/
	/* Config Timer0 in CTC mode                                            */
	/************************************************************************/
	SET_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,WGM00);
	
	
	/************************************************************************/
	/* Clear TCNT0 and set OCR0                                             */
	/************************************************************************/
	TCNT0 = TCNT0_INITIAL_VALUE;
	OCR0  = OCR0_VALUE;
	
	/************************************************************************/
	/* Set Prescaler to 64 so we can get 1ms every 250 count in OCR0        */
	/************************************************************************/
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	SET_BIT(TIMSK,OCIE0); /* enable interrupt when compare match occur */

	
}

/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: n, numer of ms 			                                    */
/* return: void			                                                */
/* Description: delay for n ms			                                */
/************************************************************************/
void TimerDelay(uint32 n)
{
	/* Reset overflow flag bit */
	SET_BIT(TIFR,TOV0);
	/* reset timer counts */
	TCNT0 = 0x00;
	/* loop to reach n */
	for (n; n > NUM_0; n--)
	{
		while(!GET_BIT(TIFR,OCF0));
		SET_BIT(TIFR,OCF0);
	}
}