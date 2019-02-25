/*
 * OS.c
 *
 * Created: 2/23/2019 3:54:42 PM
 *  Author: Yassin
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
		if(NewTickFlag == NUM_1)
		{
			prefilled(TaskArr,NUMBER_OF_TASKS);
			NewTickFlag = NUM_0 ;
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
void prefilled(tasktype TaskArr[], uint8 arr_size)
{
	for (uint8 i =NUM_0; i<arr_size; i++)
	{
		TaskArr[i]();
	}
}



