/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:57:33 PM
 *  Author: AVE-LAP-057
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "types.h"
#include "BitwiseOperations.h"
#include "CommonNumbers.h"
#include "CommonDelays.h"

#define NUMBER_OF_TASKS		3

#define TASK1				1
#define TASK2				2
#define TASK3				3

#define DELAY_SECOND		1000


typedef void(*tasktype)(void);


/************************************************************************/
/* define Array of tasks                                                */
/************************************************************************/

tasktype TaskArr[NUMBER_OF_TASKS];



#endif /* TASKS_H_ */