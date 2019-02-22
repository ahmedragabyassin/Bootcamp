/*
 * DCMotor.c
 *
 * Created: 2/21/2019 12:59:35 PM
 *  Author: AVE-LAP-057
 */ 
#include "../Includes/DCMotor.h"
void DC_Motor_Init(uint8 MotorEnablePin,uint8 MotorDirPinA,uint8 MotorDirPinB)
{
	DIO_SetPinDirection(MotorEnablePin,OUT);
	DIO_SetPinDirection(MotorDirPinA,OUT);
	DIO_SetPinDirection(MotorDirPinB,OUT);
	
}

void DC_MotorMove(uint8 MotorEnablePin,uint8 DIR_A,uint8 DIR_B, uint8 Dir)
{
	switch (Dir)
	{
		case MOTOR_FORWARD:
		if (DIO_ReadPin(DIR_A) == LOW && DIO_ReadPin(DIR_B) == HIGH )
		{
			DIO_WritePin(DIR_B,LOW);
			_delay_ms(100);
		}
		DIO_WritePin(DIR_A,HIGH);
		DIO_WritePin(DIR_B,LOW);
		//DIO_WritePin(MotorEnablePin,HIGH);
		break;
		case MOTOR_BACKWARD:
		if (DIO_ReadPin(DIR_B) == LOW && DIO_ReadPin(DIR_A) == HIGH )
		{
			DIO_WritePin(DIR_A,LOW);
			_delay_ms(100);
		}
		DIO_WritePin(DIR_B,HIGH);
		DIO_WritePin(DIR_A,LOW);
		//DIO_WritePin(MotorEnablePin,HIGH);
		break;
		case MOTOR_STOP:
		DIO_WritePin(MotorEnablePin,LOW);
		break;
	}
	
}
