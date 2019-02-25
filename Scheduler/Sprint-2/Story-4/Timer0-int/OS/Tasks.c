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



