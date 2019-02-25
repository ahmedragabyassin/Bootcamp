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
/* Description: Toggle LED0 after half second                           */
/************************************************************************/
void task1(void)
{
	DIO_TogglePin(LED0); /* Toggle LED0 */
}

/************************************************************************/
/* Function: Task2                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED1 after 750 MS                                 */
/************************************************************************/
void task2(void)
{
	DIO_TogglePin(LED1); /* Toggle LED1 */
}

/************************************************************************/
/* Function: Task3                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED2 after one second                             */
/************************************************************************/
void task3(void)
{
	DIO_TogglePin(LED2);/* Toggle LED2 */
}

/************************************************************************/
/* Function: Task4                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED4 after one second                            */
/************************************************************************/
void task4(void)
{
		DIO_TogglePin(LED3); /* Toggle LED4 */
}


/************************************************************************/
/* Function: Scheduler AddTask                                          */
/* @param: task, pointer to function                                    */
/* @param: task_periodicity,		                                    */
/* return: true or false,                                               */
/* Description: Add task to array of pointer to tasks                   */
/************************************************************************/
uint8 Scheduler_AddTask(tasktype task, uint16 task_periodicity)
{
	static uint8 task_added = NUM_0; /* static local variable to maintain its value to check if a new task added */
	if (task_added < NUMBER_OF_TASKS ) /* check if added tasks is less than the max number of tasks */
	{
		TaskArr[task_added].task = task; /* add task */
		TaskArr[task_added].task_periodicity = task_periodicity; /* add periodicity */
		TaskArr[task_added].remaining_ticks  = task_periodicity; /* load the periodicity in the remaining ticks */
		task_added++; /* increment the task added */
	}
	else
		return FALSE; /* if there is no place for new task return false and report error */
}

