/*
 * Timer.h
 *
 * Created: 2/13/2019 8:58:43 PM
 *  Author: Ahmed Yassin
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "types.h"
#include "BitwiseOperations.h"

#define TCNT0_INITIAL_VALUE			0x00
#define OCR0_VALUE					124U


/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: void			                                                */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerInit(void);

/************************************************************************/
/* Function: Timer Init                                                 */
/* @param: n, numer of ms 			                                    */
/* return: void			                                                */
/* Description: delay for n ms			                                */
/************************************************************************/
void TimerDelay(uint32 n);

/************************************************************************/
/* Function: Timer Start                                                */
/* @param: OCR, takes the value of output compare register			    */
/* return: void			                                                */
/* Description: initialize timer 		                                */
/************************************************************************/
void TimerStart(uint8 OCR);


#endif /* TIMER_H_ */