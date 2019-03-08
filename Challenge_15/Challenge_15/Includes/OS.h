/*
 * OS.h
 *
 * Created: 2/23/2019 3:54:20 PM
 *  Author: Yassin
 */ 


#ifndef OS_H_
#define OS_H_
#include "types.h"
#include "BitwiseOperations.h"
#include "CommonNumbers.h"
#include "CommonDelays.h"
#include <avr/interrupt.h>
#include "Tasks.h"
#include "../Includes/Timer.h"
#include "CommonDefinations.h"

/* Timer counting time in ms */
#define OS_TICK_INTERVAL_MSEC			124 /* value to be loaded in the OCR0 to make 1 ms*/


/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/

/************************************************************************/
/* Function: Scheduler Init										        */
/* @param: void,														*/
/* return: void,														*/
/* Description: 	*/
/************************************************************************/
void SchedulerInit(void);

/************************************************************************/
/* Function: Scheduler Start										    */
/* @param: void,														*/
/* return: void,														*/
/* Description: start the timer and scheduling							*/
/************************************************************************/
void SchedulerStart(void);

void prefilled(vTask TaskArr[], uint8 arr_size);
/************************************************************************/
/* Function: Timer0 NewTimerTick								        */
/* @param: void,														*/
/* return: void,														*/ 
/* Description: Function called by the Timer Driver in the MCAL layer	*/
/*				using the call back pointer								*/
/************************************************************************/
void Timer0_NewTimerTick(void);


/************************************************************************/
/* Function: Scheduler DeleteTask                                          */
/* @param: task, pointer to function                                    */
/* @param: task_periodicity,		                                    */
/* return: true or false,                                               */
/* Description: Add task to array of pointer to tasks                   */
/************************************************************************/
uint8 Scheduler_DeleteTask(tasktype task);

/*************************************************************************/
/* Function: Challenge Common Init                                       */
/* @param: void,														 */
/* return: void,														 */
/* Description:Init common initializations in the project like direction*/
/*************************************************************************/
void Challenge_Common_Init(void);


#endif /* OS_H_ */