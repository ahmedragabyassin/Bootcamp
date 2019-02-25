/*
 * Tasks.h
 *
 * Created: 2/23/2019 3:57:33 PM
 *  Author: Yassin
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "types.h"
#include "BitwiseOperations.h"
#include "CommonNumbers.h"
#include "CommonDelays.h"
#include "ChallengeCommonDef.h"

#define NUMBER_OF_TASKS		3

#define TASK1				1
#define TASK2				2
#define TASK3				3
#define DELAY_HALF_SECOND	1000
#define DELAY_750_MS		1500
#define DELAY_SECOND		2000

typedef void(*tasktype)(void);


/************************************************************************/
/* define Array of tasks                                                */
/************************************************************************/

tasktype TaskArr[NUMBER_OF_TASKS];

/************************************************************************/
/* Tasks Prototypes                                                     */
/************************************************************************/

/************************************************************************/
/* Function: Task1                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED1 after half second                           */
/************************************************************************/
void task1(void);

/************************************************************************/
/* Function: Task2                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED2 after 750 MS                                 */
/************************************************************************/
void task2(void);

/************************************************************************/
/* Function: Task3                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED3 after one second                             */
/************************************************************************/
void task3(void);


/************************************************************************/
/* Function: Task4                                                      */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Toggle LED4 after one second                             */
/************************************************************************/
void task4(void);


/************************************************************************/
/* Function: Task3                                                      */
/* @param: task, pointer to function                                    */
/* return: true or false,                                               */
/* Description: Toggle LED3 after one second                            */
/************************************************************************/
uint8 Scheduler_AddTask(tasktype task);


#endif /* TASKS_H_ */