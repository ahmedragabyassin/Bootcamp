/*
 * Timer0-int.c
 *
 * Created: 2/20/2019 6:03:55 PM
 * Author : Yassin
 */ 

#include "Includes/Dio.h"
#include "Includes/OS.h"


int main(void)
{
    DIO_SetPinDirection(LED1,OUT); /* Set direction of LED 1 */
	DIO_SetPinDirection(LED2,OUT); /* Set direction of LED 2 */
	DIO_SetPinDirection(LED3,OUT); /* Set direction of LED 3 */
	DIO_SetPinDirection(LED0,OUT); /* Set direction of LED 4 */
	/************************************************************************/
	/* Add Tasks to queue                                                   */
	/************************************************************************/
	if (Scheduler_AddTask(task1,DELAY_SECOND)) /* add task 1*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	if (Scheduler_AddTask(task2,DELAY_HALF_SECOND)) /* add task 2*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	
	if (Scheduler_AddTask(task3,DELAY_750_MS)) /* add task 3*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	
	if (Scheduler_AddTask(task4,DELAY_750_MS)) /* add task 4*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	/************************************************************************/
	/* Init Scheduler                                                       */
	/************************************************************************/
	SchedulerInit();
	
	/************************************************************************/
	/* Call Scheduler                                                       */
	/************************************************************************/
	SchedulerStart();
    while (NUM_1)
    {
    }
}

