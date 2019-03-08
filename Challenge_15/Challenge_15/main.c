/*
 * Challenge_15.c
 *
 * Created: 2/27/2019 1:15:26 PM
 * Author : AVE-LAP-057
 */ 

#include "Includes/KeyPad.h"
#include "Includes/Lcd.h"
#include "Includes/BCDSevSegment.h"
#include "Includes/UART.h"


int main(void)
{
	
	
    LCD_Init();
	KeyPad_Init();
	UART_Init();
	UART_Transmit('A');
	uint8 str[] = "Yassin";
	uint16 num = 123;
	LCD_intgerToString(num);
	UART_TransmitString(str,6);
	LCD_DisplayChar('A');
	uint8 pressed_key=NUM_0;
    while (1) 
    {
		pressed_key = KeyPad_GetPressedOperands();
		LCD_DisplayChar(pressed_key);
		LCD_DisplayChar(UART_receive());	
    }
}

