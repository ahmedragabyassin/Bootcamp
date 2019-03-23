

/**
 * main.c
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "spi.h"
#include "LEDs.h"
#include "LCD .h"
#include "SPI_TASK.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "include/FreeRTOS.h"
#include "include/task.h"

int main(void)
{

    xTaskCreate(Init_TASK,"INIT", 128, NULL,5,NULL);
    xTaskCreate(SPI_TASK,"SPI", 128, NULL,4,NULL);



    vTaskStartScheduler();

while(1)
{

}



	return 0;
}
