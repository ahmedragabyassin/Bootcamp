/*
 * Timer.c
 *
 * Created: 2/14/2019 9:17:34 AM
 *  Author: AVE-LAP-057
 */ 

#include "Timer.h"

void TimerInit(void)
{
	/* CTC MODE */
	TCCR0 |= (1<<WGM01);
//	TCCR0 |= (1<<COM01);
	/* 64 PRESCALLER */
	TCCR0 |= (1<<CS00);
	TCCR0 |= (1<<CS01);
	TCNT0 =0;
	OCR0 = 250; /* COMPARE VALUE */
	
}

void TimerDelay(uint32 n)
{
	TimerInit();
	TCNT0 =0;
	for (uint32 i=0; i<n; i++)
	{
		while(!(TIFR&(1<<OCF0)));
		TIFR |= (1<<OCF0);
	}
}
