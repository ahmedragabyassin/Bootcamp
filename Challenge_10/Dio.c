/*
 * Dio.c
 *
 * Created: 2/13/2019 2:34:51 PM
 *  Author: AVE-LAP-057
 */ 
#include "Dio.h"
#include "types.h"
#include "BitwiseOperations.h"


/************************************************************************/
/* Write value 0 or 1 on port                                           */
/************************************************************************/
void DIO_WritePin(uint8 PinNum, uint8 PinValue)
{
	if((PinNum >= 0) && (PinNum < 8))
	{
		if (PinValue == 1)
		{
			SET_BIT(PORTA,PinNum);
		}
		else
		{
			CLEAR_BIT(PORTA,PinNum);
		}
	}
	else if ((PinNum >= 8) && (PinNum < 16))
	{
		if (PinValue == 1)
		{
			SET_BIT(PORTB,(PinNum-8));
		}
		else
		{
			CLEAR_BIT(PORTB,(PinNum-8));
		}
	}
	else if((PinNum >= 16) && (PinNum < 24))
	{
		if(PinValue == 1)
		{
			SET_BIT(PORTC,(PinNum-16));
		}
		else
		{
			CLEAR_BIT(PORTC,(PinNum-16));
		}
	}
	else if((PinNum >= 24) && (PinNum < 32))
	{
		if (PinValue == 1)
		{
			SET_BIT(PORTD,(PinNum-24));
		}
		else
		{
			CLEAR_BIT(PORTD,(PinNum-24));
		}
	}
}

/************************************************************************/
/* Read Pin Value                                                       */
/************************************************************************/
uint8 DIO_ReadPin(uint8 PinNum)
{
		if((PinNum >= 0) && (PinNum <8))
		{
			return GET_BIT(PINA,PinNum);
		}
		else if((PinNum >= 8) && (PinNum < 16))
		{
			return GET_BIT(PINB,(PinNum-8));
		}
		else if((PinNum >= 16) && (PinNum < 24))
		{
			return GET_BIT(PINC,(PinNum-16));
		}
		else if((PinNum >= 24) && (PinNum < 32))
		{
			return GET_BIT(PIND,(PinNum-24));
		}
}


/************************************************************************/
/* Set Pin Direction                                                    */
/************************************************************************/
void DIO_SetPinDirection(uint8 PinNum, uint8 PinValue)
{
	if((PinNum >= 0) && (PinNum <8))
	{
		if (PinValue == 1)
		{
			SET_BIT(DDRA,(PinNum));
		}
		else
		{
			CLEAR_BIT(DDRA,(PinNum));
		}
	}
	else if ((PinNum >= 8) && (PinNum < 16))
	{
		if (PinValue == 1)
		{
			SET_BIT(DDRB,(PinNum-8));
			//DDRB |= (1<<(PinNum-8));
		}
		else
		{
			CLEAR_BIT(DDRB,(PinNum-8));
			//DDRB &=~ (1<<(PinNum-8));
		}
	}
	else if ((PinNum >= 16) && (PinNum < 24))
	{
		if (PinValue == 1)
		{
			SET_BIT(DDRC,(PinNum-16));
		}
		else
		{
			CLEAR_BIT(DDRC,(PinNum-16));
		}
	}
	else if ((PinNum >= 24) && (PinNum < 32))
	{
		if (PinValue == 1)
		{
			SET_BIT(DDRD,(PinNum-24));
		}
		else
		{
			CLEAR_BIT(DDRD,(PinNum-24));
		}
	}
}

