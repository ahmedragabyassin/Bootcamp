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

#define NUMBER_OF_TASKS		3 /* Max number of tasks */

#define TASK1				1 /* task 1*/
#define TASK2				2 /* task 2*/
#define TASK3				3 /* task 3*/
#define DELAY_HALF_SECOND	1000 /* delay half second */
#define DELAY_750_MS		1500 /* delay 750 ms */
#define DELAY_SECOND		2000 /* delay one second */
#define DELAY_2_SECOND		4000 /* delay one second */
#define DELAY_3_SECOND		6000 /* delay one second */

/************************************************************************/
/* define new type pointer to function                                  */
/************************************************************************/
typedef void(*tasktype)(void);


/************************************************************************/
/* define type struct to task                                           */
/************************************************************************/
typedef struct
{
	tasktype task; /* pointer to function for the task */
	uint16 task_periodicity; /* periodicity of the task */
	uint16 remaining_ticks; /* remaining ticks to perform the task */
	uint8 task_Priority; /* task priority*/
}vTask;

/************************************************************************/
/* define Array of tasks                                                */
/************************************************************************/
vTask TaskArr[NUMBER_OF_TASKS];


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



#endif /* TASKS_H_ */