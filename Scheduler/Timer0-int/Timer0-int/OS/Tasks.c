/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:57:16 PM
 *  Author: AVE-LAP-057
 */ 

#include "../Includes/Tasks.h"
#include "../Includes/Dio.h"

/************************************************************************/
/* define Array of tasks                                                */
/************************************************************************/
/************************************************************************/
/* Function: Task1                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Blink LED1                                              */
/************************************************************************/
void task1(void)
{
	
	static uint16 task1_delay = NUM_0;
	if(task1_delay >= DELAY_SECOND)
	{
		DIO_WritePin(PIN12,HIGH);
		task1_delay = 0;
	}
	task1_delay++;
}

/************************************************************************/
/* Function: Task2                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Blink LED2                                              */
/************************************************************************/
void task2(void)
{
	static uint16 task2_delay = NUM_0;
	if(task2_delay >= DELAY_SECOND)
	{
		DIO_WritePin(PIN13,HIGH);
		task2_delay = 0;
	}
	task2_delay++;
}

/************************************************************************/
/* Function: Task3                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Blink LED3                                              */
/************************************************************************/
void task3(void)
{
	static uint16 task3_delay = NUM_0;
	if(task3_delay >= DELAY_SECOND)
	{
		DIO_WritePin(PIN14,HIGH);
		task3_delay = 0;
	}
	task3_delay++;
}

tasktype TaskArr[NUMBER_OF_TASKS] = {task1, task2, task3};
