/*
 * OS.c
 *
 * Created: 2/23/2019 3:54:42 PM
 *  Author: AVE-LAP-057
 */ 

#include "../Includes/OS.h"
#include "../Includes/Dio.h"

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
	NewTickFlag = NUM_1;
	TasksCount++;
}


/************************************************************************/
/* Function: SchedulerInit_AndStart                                     */
/* @param: void						                                    */
/* return: void,                                                        */
/* Description: called in main 										    */
/************************************************************************/
void SchedulerInit_AndStart(void)
{
	sei(); /* enable global interrupt */
	TimerInit();
	/************************************************************************/
	/* Set the Call Back function call to Scheduler_New_Timer_Tick			*/
	/* this function will be called every Timer0 Compare Interrupt(ms)		*/
	/************************************************************************/ 
	Timer0_SetCallBack(Timer0_NewTimerTick);
	while(NUM_1)
	{
		prefilled(TaskArr,NUMBER_OF_TASKS);
	}
}

/************************************************************************/
/* Function: Prefilled                                                  */
/* @param: TaskArr, array of tasks                                      */
/* @param: arr_size														*/
/* return: void,                                                        */
/* Description: run tasks												*/
/************************************************************************/
void prefilled(tasktype TaskArr[], uint8 arr_size)
{
	for (uint8 i =NUM_0; i<=arr_size; i++)
	{
		if (NewTickFlag == NUM_1)
		{
			switch(TasksCount)
			{
				case TASK1:
					TaskArr[i]();
					NewTickFlag = NUM_0;
					TasksCount = NUM_0;
					break;
				case TASK2:
					TaskArr[i]();
					NewTickFlag = NUM_0;
					TasksCount = NUM_0;
					break;
				case TASK3:
					TaskArr[i]();
					NewTickFlag = NUM_0;
					TasksCount = NUM_0;
					break;
			}
		}
	}
	TasksCount = NUM_0;
}



