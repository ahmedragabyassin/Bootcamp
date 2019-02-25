/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:57:16 PM
 *  Author: Yassin
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
/* Description: Toggle LED1 after half second                            */
/************************************************************************/
void task1(void)
{
	
	static uint16 task1_delay = NUM_0;
	if(task1_delay >= DELAY_HALF_SECOND)
	{
		DIO_TogglePin(PIN12);
		task1_delay = NUM_0;
	}
	task1_delay++;
}

/************************************************************************/
/* Function: Task2                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED2 after 750 MS                                 */
/************************************************************************/
void task2(void)
{
	static uint16 task2_delay = NUM_0;
	if(task2_delay >= DELAY_750_MS)
	{
		DIO_TogglePin(PIN13);
		task2_delay = NUM_0;
	}
	task2_delay++;
}

/************************************************************************/
/* Function: Task3                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED3 after one second                             */
/************************************************************************/
void task3(void)
{
	static uint16 task3_delay = NUM_0;
	if(task3_delay >= DELAY_SECOND)
	{
		DIO_TogglePin(PIN14);
		task3_delay = NUM_0;
	}
	task3_delay++;
}

tasktype TaskArr[NUMBER_OF_TASKS] = {task1, task2, task3};
