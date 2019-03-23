/*
 * SPI_TASK.c
 *
 *  Created on: Mar 21, 2019
 *      Author: AVE-LAP-023
 */

#include "SPI_TASK.h"
#include "LCD .h"
#include "spi.h"
#include "LEDs.h"



#define ULTRASONIC_FACTOR   2.55535
#define FIVE_SHIFT          5
#define DATA_MASK           0x1F

volatile uint8_t command ;
volatile uint8_t distance;

/************************************************************************/
/* Function: Analysis_Data                                              */
/* @param: data                                                         */
/* return: command, distance                                            */
/* Description: function takes the data and divided it into command     */
/*              distance                                                */
/************************************************************************/
void AlignData_recv(uint8_t data)
{
    command  = data >> FIVE_SHIFT;
    distance = data & DATA_MASK;
}

/******************************************************************************************************************
 * Function name :- SPI_TASK
 * Function job :- waith spi to recieve then display state
 * Function arguments :- N/A
 * Function return :- N/A
 ********************************************************************************************************************/
void SPI_TASK (void*pv)
{

    uint8_t data;

    while(1)
    {
        if(SSIDataGetNonBlocking(SSI3_BASE,&data)!=0)
        {
           AlignData_recv(data);
            switch (command)
            {
            case IGN_ON_OFF:
                LCD_Clear();
                LCD_displayString("State:");
                LCD_Display_NUM(command);
                break;
            case MAINTAIN_SPEEED:
                LCD_Clear();
                LCD_displayString("State:");
                LCD_Display_NUM(command);
                LCD_gotoRowColumn(LCD_ROW2, LCD_COL1);
                LCD_displayString("Distance:");

                LCD_Display_NUM(distance);
                break;
            case INCREASE_SPEEED:
                LCD_Clear();
                LCD_displayString("State:");
                LCD_Display_NUM(command);
                LCD_gotoRowColumn(LCD_ROW2, LCD_COL1);
                LCD_displayString("Distance");

                LCD_Display_NUM(distance);
                break;
            case DECREASE_SPEEED:
                LCD_Clear();
                LCD_displayString("State:");
                LCD_Display_NUM(command);
                LCD_gotoRowColumn(LCD_ROW2, LCD_COL1);
                LCD_displayString("Distance");

                LCD_Display_NUM(distance);
                break;
            case BRAKES:
                LCD_Clear();
                LCD_displayString("State:");
                LCD_Display_NUM(command);
                LCD_gotoRowColumn(LCD_ROW2, LCD_COL1);
                LCD_displayString("Distance");

                LCD_Display_NUM(distance);
                break;
            case FIRE_AIR_BAG:
                LCD_Clear();
                LCD_displayString("State:");

                LCD_Display_NUM(command);
                break;
            default:
                break;
            }

            /* put recieved data in queue */
        }
        vTaskDelay(20);
    }



}

/******************************************************************************************************************
 * Function name :- Init_TASK
 * Function job :- intiate all modules
 * Function arguments :- N/A
 * Function return :- N/A
 ********************************************************************************************************************/
void Init_TASK (void*pv)
{

/*initiate spi and lcd */

    while(1)
    {
       SPI_init_S();
       LEDs_Init();
       LCD_init();
       LCD_displayString("Welcome To HELL");
        vTaskSuspend(NULL);
    }



}



