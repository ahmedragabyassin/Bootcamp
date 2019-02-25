/*
 * Timer0-int.c
 *
 * Created: 2/20/2019 6:03:55 PM
 * Author : AVE-LAP-057
 */ 

#include "Includes/Timer.h"
#include "Includes/Dio.h"
#include "Includes/Interrupts.h"
#include "Includes/OS.h"





int main(void)
{
    DIO_SetPinDirection(LED1,OUT); /* LED 1 */
	DIO_SetPinDirection(LED2,OUT); /* LED 2 */
	DIO_SetPinDirection(LED3,OUT); /* LED 3 */
	DIO_SetPinDirection(PIN12,OUT);  /* button one*/
	
	Interrupts_init();
	SchedulerInit_AndStart();
    while (NUM_1)
    {
    }
}

