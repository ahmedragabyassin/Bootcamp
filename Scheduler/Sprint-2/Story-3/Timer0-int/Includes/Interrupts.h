/*
 * Interrupts.h
 *
 * Created: 2/21/2019 12:02:45 AM
 *  Author: Ahmed Yassin
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include <avr/interrupt.h>
#include "types.h"
#include "CommonDefinations.h"
#include "CommonDelays.h"
#include "CommonNumbers.h"
#include "Dio.h"
#include "BitwiseOperations.h"

/************************************************************************/
/* Function: Interrupts Init                                            */
/* @param: void,                                                        */
/* return: void,                                                        */
/* Description: Init interrupts                                         */
/************************************************************************/
void Interrupts_init(void);


#endif /* INTERRUPTS_H_ */