/*
 * Timer0-int.c
 *
 * Created: 2/20/2019 6:03:55 PM
 * Author : AVE-LAP-057
 */ 

#include <avr/interrupt.h>
#include "Includes/Timer.h"
#include "Includes/Dio.h"
#include "Includes/Interrupts.h"

/************************************************************************/
/* State machine conditions                                             */
/************************************************************************/
#define READY		NUM_0
#define GO			NUM_1
#define STOP		NUM_2




int main(void)
{
    uint8 state = GO; /* initial state to state machine */
	DIO_SetPinDirection(PIN13,OUT); /* LED 1 */
	DIO_SetPinDirection(PIN14,OUT); /* LED 2 */
	DIO_SetPinDirection(PIN15,OUT); /* LED 3 */
	DIO_SetPinDirection(PIN10,IN);  /* button one*/
	
	TimerInit();
	Interrupts_init();
    while (1) 
    {
			switch(state)
				{
					case READY:
						DIO_WritePin(PIN14,HIGH);
						DIO_WritePin(PIN13,LOW);
						DIO_WritePin(PIN15,LOW);
						if (int2 > NUM_0)
						{
							state = STOP;
							Gtick = NUM_0;
							int2  = NUM_0;
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
						if (int2 >NUM_0)
						{
							state = STOP;
							Gtick = NUM_0;
							int2  = NUM_0;
						}
						if (Gtick >= NUM_OVERFLOWS)
						{
							state = STOP;
							Gtick = NUM_0;
						}
						break;
					case STOP:
						DIO_WritePin(PIN15,HIGH);
						DIO_WritePin(PIN13,LOW);
						DIO_WritePin(PIN14,LOW);
						if (int2 > NUM_0)
						{
							state = STOP;
							Gtick = NUM_0;
							int2  = NUM_0;
						}
						if (Gtick >= NUM_OVERFLOWS)
						{
							state = READY;
							Gtick = NUM_0;
						}
						break;
						
						default: break;
				}

    }
}

