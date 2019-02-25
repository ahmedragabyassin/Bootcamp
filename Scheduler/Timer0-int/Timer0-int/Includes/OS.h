/*
 * OS.h
 *
 * Created: 2/23/2019 3:54:20 PM
 *  Author: AVE-LAP-057
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

/* Timer counting time in ms */
#define OS_TICK_INTERVAL_MSEC			124


/************************************************************************/
/* Functions prototypes                                                 */
/************************************************************************/


void SchedulerInit_AndStart(void);
void prefilled(tasktype TaskArr[], uint8 arr_size);
/************************************************************************/
/* Function: Timer0 NewTimerTick								        */
/* @param: void,														*/
/* return: void,														*/ 
/* Description: Function called by the Timer Driver in the MCAL layer	*/
/*				using the call back pointer								*/
/************************************************************************/
void Timer0_NewTimerTick(void);




#endif /* OS_H_ */