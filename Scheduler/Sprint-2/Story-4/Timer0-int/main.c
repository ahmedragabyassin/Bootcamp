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
	Challenge_Common_Init();
	/************************************************************************/
	/* Add Tasks to queue                                                   */
	/************************************************************************/
	if (Scheduler_AddTask(task1,DELAY_HALF_SECOND,NUM_2)) /* add task 1*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	if (Scheduler_AddTask(task2,DELAY_750_MS,NUM_1)) /* add task 2*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	
	if (Scheduler_AddTask(task3,DELAY_SECOND,NUM_0)) /* add task 3*/
	{
		
	}else
	{
		DIO_WritePin(LED3,HIGH);/* if task not added then there is an error here and led4 will blink */
	}
	
	if (Scheduler_AddTask(task4,DELAY_750_MS,NUM_3)) /* add task 4*/
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

