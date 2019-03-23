
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "FreeRTOS/Includes/FreeRTOS.h"
#include "FreeRTOS/Includes/task.h"
#include "FreeRTOS/Includes/queue.h"
#include "FreeRTOS/Includes/semphr.h"
#include "Drivers/LEDs/inc/LEDs.h"
#include "Drivers/Switch/inc/Switch.h"
#include "FreeRTOS/Includes/event_groups.h"
#include "Tasks.h"
#include "FSM.h"
#include "Drivers/LCD/inc/LCD.h"
#include "Drivers/KeyPad/inc/Keypad.h"
#include "Drivers/UART/inc/uart.h"
#include "Drivers/SPI/inc/spi.h"


/******************************************************************************/
/* The Queue size and length definations.                                     */
/******************************************************************************/
#define QUEUE_LENGTH          10
#define QUEUE_SPI_SIZE       sizeof(uint16_t)
#define QUEUE_MANAGER_SIZE   sizeof(uint8_t)

/******************************************************************************/
/* The stack size for the FSM task.                                           */
/******************************************************************************/
#define FSMSTASKSTACKSIZE           200
/******************************************************************************/
/* The stack size for manager task.                                            */
/******************************************************************************/
#define MANAGERSTASKSTACKSIZE        200
/******************************************************************************/
/* The stack size for the SW task.                                            */
/******************************************************************************/
#define SWTASKSTACKSIZE        128

/******************************************************************************/
/* The stack size for the Main task.                                          */
/******************************************************************************/
#define MAINTASKSTACKSIZE        128


/******************************************************************************/
/* The priorities of the various tasks.                                       */
/******************************************************************************/
#define PRIORITY_MAIN_TASK          5
#define PRIORITY_FSM_TASK           2
#define PRIORITY_SW_TASK            4
#define PRIORITY_MANAGER_TASK       3
//*****************************************************************************/
/* The error routine that is called if the driver library encounters an error.*/
//*****************************************************************************/
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif

/*****************************************************************************/
/* This hook is called by FreeRTOS when an stack overflow error is detected. */
/*****************************************************************************/
void
vApplicationStackOverflowHook(xTaskHandle *pxTask, char *pcTaskName)
{
    /***************************************************************************/
    /* This function can not return, so loop forever.  Interrupts are disabled */
    /* on entry to this function, so no processor interrupts will interrupt    */
    /* this loop.                                                              */
    /***************************************************************************/
    while(1)
    {
    }
}



int main(void)
{
        /***************************************************/
        /* Set the clocking to run at 50 MHz from the PLL. */
        /***************************************************/
        ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                           SYSCTL_OSC_MAIN);


        /***************************************************/
        /* Create Event Group flags  that notify the tasks.*/
       /***************************************************/
        xCreatedEventGroup_Flags = xEventGroupCreate();

        /***************************************************/
        /* Create Queues  for communication between tasks. */
        /***************************************************/
        QueueManager = xQueueCreate( QUEUE_LENGTH, QUEUE_MANAGER_SIZE );
        QueueSPI     = xQueueCreate( QUEUE_LENGTH, QUEUE_SPI_SIZE );


        /***************************************************/
        /* Create MainTaks that initialize the drivers.    */
        /***************************************************/
        xTaskCreate(MainTaskInit, (const portCHAR *)"MainInit", MAINTASKSTACKSIZE, NULL,
                           tskIDLE_PRIORITY + PRIORITY_MAIN_TASK, NULL);



        /***************************************************/
        /* Create SWTask that check the button status.     */
        /***************************************************/
        xTaskCreate(SW_2_Task, (const portCHAR *)"SW1", SWTASKSTACKSIZE, NULL,
                                       tskIDLE_PRIORITY + PRIORITY_SW_TASK, NULL);

        xTaskCreate(Manager_Task, (const portCHAR *)"Manager_T", MAINTASKSTACKSIZE, NULL,
                                           tskIDLE_PRIORITY + PRIORITY_MANAGER_TASK, NULL);

        /*****************************************************/
        /* Create FSM Task                                   */
        /*****************************************************/
        xTaskCreate(FSM_Task, (const portCHAR *)"FSM_T", FSMSTASKSTACKSIZE, NULL,
                                                       tskIDLE_PRIORITY + PRIORITY_FSM_TASK, NULL);


        /******************************************************************************/
        /* Start the scheduler.  This should not return.                              */
        /******************************************************************************/
        vTaskStartScheduler();

        /**********************************************************************************/
        /* In case the scheduler returns for some reason, print an error and loop forever.*/
        /**********************************************************************************/
        while(1)
        {
        }


}
