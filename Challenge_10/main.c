/*
 * challenge_10.c
 *
 * Created: 2/13/2019 10:55:01 AM
 * Author : AVE-LAP-057
 */ 

#include "types.h"
#include "BitwiseOperations.h"
#include "Dio.h"
//#include "Delay.h"
#include "Timer.h"

#define READY		0
#define GO			1
#define STOP		2

#ifndef F_CPU
#define F_CPU 16000000U
//#include <util/delay.h>
#endif
int main(void)
{
    /* Replace with your application code */
	
	//DIO_SetPinDirection(PIN10,IN); /* Button 1 */
	//DIO_SetPinDirection(PIN12,OUT);
	DIO_SetPinDirection(PIN13,OUT); /* LED 1 */
	DIO_SetPinDirection(PIN14,OUT); /* LED 2 */
	DIO_SetPinDirection(PIN15,OUT); /* LED 3 */
	//TimerInit();
			
    while (1) 
    {
		/*DIO_WritePin(14,HIGH);
		TimerDelay(1000);
		DIO_WritePin(14,LOW);
		TimerDelay(1000);
		DIO_WritePin(13,HIGH);
		TimerDelay(1000);
		DIO_WritePin(13,LOW);
		TimerDelay(1000);
		DIO_WritePin(15,HIGH);
		TimerDelay(1000);
		DIO_WritePin(15,LOW);
		*/
			uint8 state = READY;
			switch(state)
			{
				case READY:
					state = GO;
					DIO_WritePin(PIN14,HIGH);
					TimerDelay(1000);
					DIO_WritePin(PIN14,LOW);
					break;
				case GO:
					DIO_WritePin(PIN13,HIGH);
					TimerDelay(1000);
					state = STOP;
					DIO_WritePin(PIN13,LOW);
					break;
				case STOP:
					DIO_WritePin(PIN15,HIGH);
					TimerDelay(1000);
					state = READY;
					DIO_WritePin(PIN15,LOW);
					break;
				default: break;
			}

    }
}

