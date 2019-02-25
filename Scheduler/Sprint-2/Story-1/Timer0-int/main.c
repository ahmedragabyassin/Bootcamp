/*
 * Timer0-int.c
 *
 * Created: 2/20/2019 6:03:55 PM
 * Author : Yassin
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
	DIO_SetPinDirection(LED0,OUT);  /* button one*/
	
	Interrupts_init();
	Scheduler_AddTask(task1);
	Scheduler_AddTask(task2);
	Scheduler_AddTask(task3);
	Scheduler_AddTask(task4);
	SchedulerInit_AndStart();
    while (NUM_1)
    {
    }
}

