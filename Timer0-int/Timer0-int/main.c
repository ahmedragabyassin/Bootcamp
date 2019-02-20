/*
 * Timer0-int.c
 *
 * Created: 2/20/2019 6:03:55 PM
 * Author : AVE-LAP-057
 */ 

#include <avr/interrupt.h>
#include "Includes/Timer.h"
#include "Includes/Dio.h"
#define NUM_OVERFLOWS			2000

#define READY		NUM_0
#define GO			NUM_1
#define STOP		NUM_2

volatile uint64 Gtick = NUM_0;
volatile uint8 int0 = NUM_0;

/************************************************************************/
/* Interrupt to handle if button pressed                                */
/************************************************************************/
ISR(INT2_vect)
{
	int0++;
}


ISR(TIMER0_COMP_vect)
{
	Gtick++;
}



int main(void)
{
    uint8 state = GO;
	DIO_SetPinDirection(PIN13,OUT); /* LED 1 */
	DIO_SetPinDirection(PIN14,OUT); /* LED 2 */
	DIO_SetPinDirection(PIN15,OUT); /* LED 3 */
	DIO_SetPinDirection(PIN10,IN);
	//DIO_WritePin(PIN10,HIGH);
	
	TimerInit();
	
    while (1) 
    {
			switch(state)
				{
					case READY:
						DIO_WritePin(PIN14,HIGH);
						DIO_WritePin(PIN13,LOW);
						DIO_WritePin(PIN15,LOW);
						if (int0 >0)
						{
							state = STOP;
							Gtick = NUM_0;
							int0  = NUM_0;
						}
						if (Gtick >= NUM_OVERFLOWS)
						{
							state = GO;
							Gtick = NUM_0;
						}
						break;
					case GO:
						DIO_WritePin(PIN13,HIGH);
						DIO_WritePin(PIN14,LOW);
						DIO_WritePin(PIN15,LOW);
						if (int0 >0)
						{
							state = STOP;
							Gtick = 0;
							int0  = NUM_0;
						}
						if (Gtick >= NUM_OVERFLOWS)
						{
							state = STOP;
							Gtick = 0;
						}
						break;
					case STOP:
						DIO_WritePin(PIN15,HIGH);
						DIO_WritePin(PIN13,LOW);
						DIO_WritePin(PIN14,LOW);
						if (int0 > 0)
						{
							state = STOP;
							Gtick = 0;
							int0  = NUM_0;
						}
						if (Gtick >= NUM_OVERFLOWS)
						{
							state = READY;
							Gtick = 0;
						}
						break;
						
						default: break;
				}

    }
}

