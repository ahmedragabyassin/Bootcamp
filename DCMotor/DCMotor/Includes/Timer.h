/*
 * Timer.h
 *
 * Created: 2/13/2019 8:58:43 PM
 *  Author: Ahmed Yassin
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/************************************************************************/
/* Include required header files                                        */
/************************************************************************/
#include "types.h"
#include "BitwiseOperations.h"
#include "CommonDefinations.h"

/************************************************************************/
/* Define max and top values for the timer                              */
/************************************************************************/
#define TOP_VALUE			1900
#define MAX_VALUE			2000


/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerInit(void);


/************************************************************************/
/* Function: Timer 1 Init                                               */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: initialize timer 1 		                                */
/************************************************************************/
void TimerOneInit(uint8 DutyCycle);


/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: n, numer of ms 			                                    */
/* return: void			                                                */
/* Description: delay for n ms			                                */
/************************************************************************/
void TimerDelay(uint32 n);




#endif /* TIMER_H_ */