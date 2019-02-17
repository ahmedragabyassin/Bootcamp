/*
 * Timer.h
 *
 * Created: 2/14/2019 9:17:17 AM
 *  Author: AVE-LAP-057
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "types.h"
#include "BitwiseOperations.h"

#define TCCR0			(*(volatile uint8 *)(0x53))
#define TCNT0			(*(volatile uint8 *)(0x52))
#define OCR0			(*(volatile uint8 *)(0x5C))
#define TIMSK			(*(volatile uint8 *)(0x59))
#define TIFR			(*(volatile uint8 *)(0x58))
#define TWCR			(*(volatile uint8 *)(0x56))

/************************************************************************/
/* TCCR0 Bits                                                           */
/************************************************************************/
#define CS00			0
#define CS01			1
#define CS02			2
#define	WGM01			3
#define COM00			4
#define COM01			5
#define WGM00			6
#define FOC0			7

/************************************************************************/
/* TIMSK Bits                                                           */
/************************************************************************/

#define TOIE0			0
#define	OCIE0			1
#define TOIE1			2
#define OCIE1B			3
#define OCIE1A			4
#define TICIE1			5
#define TOIE2			6
#define OCIE2			7


/************************************************************************/
/* TIFR Bits                                                            */
/************************************************************************/
#define TOV0			0
#define OCF0			1
#define	TOV1			2
#define OCF1B			3
#define OCF1A			4
#define ICF1			5
#define	TOV2			6
#define OCF2			7


void TimerInit(void);
void TimerDelay(uint32 n);




#endif /* TIMER_H_ */