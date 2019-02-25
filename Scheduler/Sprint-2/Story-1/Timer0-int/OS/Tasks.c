/*
 * Tasks.c
 *
 * Created: 2/23/2019 3:57:16 PM
 *  Author: Yassin
 */ 

#include "../Includes/Tasks.h"
#include "../Includes/Dio.h"

/************************************************************************/
/* Function: Task1                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED1 after half second                           */
/************************************************************************/
void task1(void)
{
	
	static uint16 task1_delay = NUM_0;
	if(task1_delay >= DELAY_HALF_SECOND)
	{
		DIO_TogglePin(LED0);
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
		DIO_TogglePin(LED1);
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
		DIO_TogglePin(LED2);
		task3_delay = NUM_0;
	}
	task3_delay++;
}

/************************************************************************/
/* Function: Task4                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED0 after one second                            */
/************************************************************************/
void task4(void)
{
	static uint16 task4_delay = NUM_0;
	if(task4_delay >= DELAY_SECOND)
	{
		DIO_TogglePin(LED3);
		task4_delay = NUM_0;
	}
	task4_delay++;
}


/************************************************************************/
/* Function: Scheduler AddTask                                          */
/* @param: task, pointer to function                                    */
/* return: true or false,                                               */
/* Description: Add task to array of pointer to tasks                   */
/************************************************************************/
uint8 Scheduler_AddTask(tasktype task)
{
	static uint8 task_added = NUM_0;
	if (task_added < NUMBER_OF_TASKS )
	{
		TaskArr[task_added] = task;
		task_added++;
	}
	else
		return FALSE;
}

