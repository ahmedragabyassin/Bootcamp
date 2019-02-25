/*
 * Timer.c
 *
 * Created: 2/13/2019 8:58:21 PM
 *  Author: Ahmed Yassin
 */ 

#include "../Includes//Timer.h"
#include "../Includes/TimerMemMap.h"
#include "../Includes/Interrupts.h"
#include "../Includes/Dio.h"


/************************************************************************/
/* Global pointer to function used to point upper layer functions		*/
/* to be used in Call Back												*/
/************************************************************************/
volatile void (*G_Timer0_Call_Back_Ptr)(void) = NULL_PTR;


/*********************************************************************************/
/* Function: Call Back function                                                  */
/* @param: pointer to function,                                                  */
/* return: void,												                 */
/* Description: Points to the required function in the OS upper layer Scheduler  */
/*********************************************************************************/
void Timer0_SetCallBack(void(*Ptr2Func)(void))
{
	G_Timer0_Call_Back_Ptr = Ptr2Func;
}


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
/* Function: Interrupts Init                                            */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Init interrupts                                         */
/************************************************************************/
void Interrupts_init(void)
{
	sei(); /* enable global interrupt */
}


/************************************************************************/
/* Interrupt to handle when compare match occur                        */
/************************************************************************/
ISR(TIMER0_COMP_vect)
{
	if (G_Timer0_Call_Back_Ptr != NULL_PTR)
	{
		G_Timer0_Call_Back_Ptr(); /* call the function in the scheduler using call-back */
	}
}
