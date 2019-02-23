/*
 * Timer.c
 *
 * Created: 2/13/2019 8:58:21 PM
 *  Author: Ahmed Yassin
 */ 


#include "../Includes//Timer.h"
#include "../Includes/TimerMemMap.h" /* memory map for registers */


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
	TCNT0 =0x00;
	OCR0 = 124U;
	
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
/* @param: DutyCycle, 			                                        */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerOneInit(uint8 DutyCycle)
{
	
	uint16 OCR_value = (MAX_VALUE - ((DutyCycle * (MAX_VALUE + 1 ) ))/NUM_100);
	/************************************************************************/
	/* initialize registers                                                 */
	/************************************************************************/
	TCNT1H = NUM_0;
	TCNT1L = NUM_0;
	
	OCR1AH = (OCR_value>>SHIFT_EIGHT); /* set ocr1 to 1000 */
	OCR1AL = OCR_value;
	
	OCR1BH = (OCR_value>>SHIFT_EIGHT); /* set ocr1 to 1000 */
	OCR1BL = OCR_value;
	
	ICR1L = MAX_VALUE;
	ICR1H = (MAX_VALUE>>SHIFT_EIGHT);
	
	/************************************************************************/
	/* Config Timer1 in PWM phase correct mode                              */
	/************************************************************************/
	SET_BIT(TCCR1A,COM1A1);
	//SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1B1);
	//SET_BIT(TCCR1A,COM1B0);
	
	CLEAR_BIT(TCCR1A,FOC1A);
	CLEAR_BIT(TCCR1A,FOC1B);
	
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM13);
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1A,WGM10);

	
}


/************************************************************************/
/* Function: Timer delay                                                */
/* @param: n, number of ms 			                                    */
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
	for (n; n>0; n++)
	{
		while(!(TIFR&(1<<OCF0)));
		TIFR |= (1<<OCF0);
	}
}