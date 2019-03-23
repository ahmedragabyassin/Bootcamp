/*
 * Tasks.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-057
 */




#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"
#include "tasks.h"
#include "FreeRTOS/Includes/task.h"
#include "FreeRTOS/Includes/semphr.h"
#include "Drivers/Switch/inc/Switch.h"
#include "Drivers/LEDs/inc/LEDs.h"
#include "tasks.h"
#include "Drivers/LCD/inc/LCD.h"
#include "Drivers/KeyPad/inc/Keypad.h"
#include "Drivers/UART/inc/uart.h"
#include "Drivers/SPI/inc/spi.h"


#define SW_BIT   ( 1 << 4 )
/******************************************************************************/
/* Switch flag to check if the button is pressed or not.                      */
/******************************************************************************/
volatile uint8_t WS_Flag = 0;

/********************************************************************************/
/* Default LED toggle delay value. LED toggling frequency is twice this number. */
/****************************************************************************** */
#define LED_TOGGLE_DELAY        10

/********************************************************************************/
/* Default LED toggle delay value. LED toggling frequency is twice this number. */
/****************************************************************************** */
#define SW_DELAY        10
#define SW_DEBOUN       1000


#define T_DELAY_1000                      1000
#define T_DELAY_10                        10
#define T_DELAY_100                       100
#define T_DELAY_50                        50

/******************************************************************************/
/* buffer to hold the values entered from keypad.                             */
/******************************************************************************/


volatile uint8_t Key_ret;

/******************************************************************************/
/* Queue handlers.                                                            */
/******************************************************************************/
QueueHandle_t QueueManager;
QueueHandle_t QueueSPI;

/* Declare a variable to hold the created event group. */
EventGroupHandle_t xCreatedEventGroup_Flags;



/******************************************************************************/
/* This task Check if the button is pressed or not                            */
/******************************************************************************/
void SW_1_Task(void *pvParameters)
{
    vTaskDelay(T_DELAY_100); /* delay till all modules intialized */
    while(NUM_1)
    {
        if(SW_1_Status())
        {
            while(SW_1_Status())
            {
                xEventGroupSetBits( xCreatedEventGroup_Flags, SW_BIT );/* The bits being set. */
                vTaskDelay(SW_DEBOUN);
            }
        }
        vTaskDelay(SW_DELAY);
    }
}



/******************************************************************************/
/* This task Init the leds and Switches                                       */
/******************************************************************************/
void MainTaskInit(void *pvParameters)
{
    while(1)
    {
        LEDs_Init();
        Switch_Init();
        Keypad_Init();
        UART0_init();
        SPI_init_M();
        //LCD_init();
        //LCD_gotoRowColumn(LCD_ROW2, LCD_COL1);
      //  LCD_displayString("Welcome TO HELL ");
        vTaskSuspend( NULL );
    }
}

#if 0
/******************************************************************************/
/* This task in the Slave ECU to display the state and distance               */
/******************************************************************************/
void LCDTask(void *pvParameters)
{
    vTaskDelay(T_DELAY_100); /* delay till all modules intialized */
    while(1)
    {

    }
}


#endif

