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
volatile uint8 TasksCount  = NUM_0; /* count number of ticks */


/************************************************************************/
/* Function: Timer0 NewTimerTick                                        */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Function called by the Timer Driver in the MCAL layer	*/
/*				using the call back pointer								*/
/************************************************************************/
void Timer0_NewTimerTick(void)
{
	NewTickFlag = NUM_1; /* Set Flag that interrupt timer compare match occ*/
	TasksCount++;
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
				prefilled(TaskArr,NUMBER_OF_TASKS); /* call the function that do task */
				NewTickFlag = NUM_0 ; /* clear the flag */
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



