/*
 * SPI_TASK.h
 *
 *  Created on: Mar 21, 2019
 *      Author: AVE-LAP-023
 */

#ifndef SPI_TASK_H_
#define SPI_TASK_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "inc/hw_memmap.h"
#include "driverlib/ssi.h"
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/event_groups.h"
#include "include/queue.h"

#define SPI_BIT (1<<1)

/* Common States Defination                                                   */
/******************************************************************************/
#define IGN_ON_OFF          0
#define MAINTAIN_SPEEED     1
#define INCREASE_SPEEED     2
#define DECREASE_SPEEED     3
#define BRAKES              4
#define FIRE_AIR_BAG        5

/******************************************************************************/
/* Common Used Distances                                                      */
/******************************************************************************/
#define MAINTAIN_SPEED_HIGH             22
#define MAINTAIN_SPEED_LOW              15
#define INCREASE_SPEED_HIGH             30
#define INCREASE_SPEED_LOW              22
#define DECREASE_SPEED_HIGH             15
#define DECREASE_SPEED_LOW              10
#define BRAKES_HIGH                     10
#define BRAKES_LOW                      3
#define FIRE_AIR_BAG_HIGH               3
#define FIRE_AIR_BAG_LOW                0


void SPI_TASK (void*pv);
void Init_TASK (void*pv);


#endif /* SPI_TASK_H_ */
