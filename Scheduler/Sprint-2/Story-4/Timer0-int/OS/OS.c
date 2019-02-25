/*
 * OS.c
 *
 * Created: 2/23/2019 3:54:42 PM
 *  Author: Yassin
 */ 

#include "../Includes/OS.h"
#include "../Includes/Dio.h"
#include "../Includes/Interrupts.h"


volatile uint8 NewTickFlag = NUM_0; /* flag when interrupt occurs set to one */
static uint8 TasksCount    = NUM_0; /* count number of ticks */
static uint8 task_added	   = NUM_0; /* static local variable to maintain its value to check if a new task added */

/************************************************************************/
/* Function: Timer0 NewTimerTick                                        */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Function called by the Timer Driver in the MCAL layer	*/
/*				using the call back pointer								*/
/************************************************************************/
void Timer0_NewTimerTick(void)
{
	NewTickFlag = NUM_1; /* Set Flag that interrupt timer compare match OCR*/
}


/************************************************************************/
/* Function: SchedulerInit			                                    */
/* @param: void						                                    */
/* return: void,                                                        */
/* Description: called in main 										    */
/************************************************************************/
void SchedulerInit(void)
{
	Interrupts_init(); /* initialize global interrupts */
	TimerInit();		/* init timer */
	/************************************************************************/
	/* Set the Call Back function call to Scheduler_New_Timer_Tick			*/
	/* this function will be called every Timer0 Compare Interrupt(ms)		*/
	/************************************************************************/ 
	Timer0_SetCallBack(Timer0_NewTimerTick);
}


/************************************************************************/
/* Function: Scheduler Start										    */
/* @param: void,														*/
/* return: void,														*/
/* Description: start the timer and scheduling							*/
/************************************************************************/
void SchedulerStart(void)
{
		TimerStart(OS_TICK_INTERVAL_MSEC); /* start timer */
		while(NUM_1)
		{
			if(NewTickFlag == NUM_1) /* check if flag is set */
			{
				prefilled(TaskArr,TasksCount); /* call the function that do task */
				NewTickFlag = NUM_0 ; /* clear the flag */
			}
			if (DIO_ReadPin(BUTTON1)) /* check if button is pressed */
			{
				if(!DIO_ReadPin(BUTTON1))
				{if (Scheduler_DeleteTask(task1)) /* call the scheduler delete task */
				{
				}
				else{}
				}
				/* handle here if task not deleted */
			}
			
		}
}


/************************************************************************/
/* Function: Prefilled                                                  */
/* @param: TaskArr, array of tasks                                      */
/* @param: arr_size														*/
/* return: void,                                                        */
/* Description: run tasks												*/
/************************************************************************/
void prefilled(vTask TaskArr[], uint8 arr_size)
{
	for (uint8 i =NUM_0; i<arr_size; i++) /* for loop to check for all tasks in the array */
	{	/* if the remaining task in task is zero then do the task now and load the periodicity in remaining again */
		if (TaskArr[i].remaining_ticks == NUM_0) 
		{
			TaskArr[i].task();/* call the task */
			TaskArr[i].remaining_ticks = TaskArr[i].task_periodicity; /*load the periodicity in remaining again to do the task again */
		}
		TaskArr[i].remaining_ticks--; /* decrement the remaining ticks */
	}
}


/************************************************************************/
/* Function: Scheduler AddTask                                          */
/* @param: task, pointer to function                                    */
/* @param: task_periodicity,		                                    */
/* return: true or false,                                               */
/* Description: Add task to array of pointer to tasks                   */
/************************************************************************/
uint8 Scheduler_AddTask(tasktype task, uint16 task_periodicity, uint8 task_priority)
{
	if (task_added < NUMBER_OF_TASKS ) /* check if added tasks is less than the max number of tasks */
	{
		TaskArr[task_added].task = task; /* add task */
		TaskArr[task_added].task_periodicity = task_periodicity + task_priority; /* add periodicity */
		TaskArr[task_added].remaining_ticks  = task_periodicity + task_priority; /* load the periodicity in the remaining ticks */
		TaskArr[task_added].task_Priority		= task_priority; /* add the priority */
		task_added++; /* increment the task added */
		TasksCount++; /*increment tasks*/
	}
	else
	return FALSE; /* if there is no place for new task return false and report error */
}



/************************************************************************/
/* Function: Scheduler AddTask                                          */
/* @param: task, pointer to function                                    */
/* @param: task_periodicity,		                                    */
/* return: true or false,                                               */
/* Description: Delete task to array of pointer to tasks                   */
/************************************************************************/
uint8 Scheduler_DeleteTask(tasktype task)
{
		for (uint8 task_index = NUM_0; task_index <= TasksCount; task_index++) /* search for the task */
		{
			if (TaskArr[task_index].task == task) /* if task found then delete and shift */
			{
				for (uint8 task_index_j = task_index; task_index_j < TasksCount; task_index_j++)
				{
					TaskArr[task_index_j].task = TaskArr[task_index_j + NUM_1].task; /* shift task */
					TaskArr[task_index_j].task_periodicity = TaskArr[task_index_j + NUM_1].task_periodicity; /* shift periodicity */
					TaskArr[task_index_j].remaining_ticks  = TaskArr[task_index_j + NUM_1].remaining_ticks; /* shift the remaining ticks */
					TaskArr[task_index_j].task_Priority    = TaskArr[task_index_j + NUM_1].task_Priority; /* shift the priority */
				}
			}
			else
				return FALSE; /* if there is no place for new task return false and report error */
		}
		TasksCount--; /* decrement tasks */
		task_added--; /* decrement added task */
}



/*************************************************************************/
/* Function: Challenge Common Init                                       */
/* @param: void,														 */
/* return: void,														 */
/* Description:Init common initializations in the project like direction*/
/*************************************************************************/
void Challenge_Common_Init(void)
{
	DIO_SetPinDirection(LED1,OUT); /* Set direction of LED 1 */
	DIO_SetPinDirection(LED2,OUT); /* Set direction of LED 2 */
	DIO_SetPinDirection(LED3,OUT); /* Set direction of LED 3 */
	DIO_SetPinDirection(LED0,OUT); /* Set direction of LED 4 */
	DIO_SetPinDirection(BUTTON1,IN);/* Set Button Direction */
}