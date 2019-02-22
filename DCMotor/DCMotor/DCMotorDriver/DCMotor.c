/*
 * DCMotor.c
 *
 * Created: 2/21/2019 12:59:35 PM
 *  Author: AVE-LAP-057
 */ 
#include "../Includes/DCMotor.h"


/************************************************************************/
/* Function: DC Motor Init                                              */
/* @param: MotorEnablePin, enable pin for the motor                     */
/* @param: MotorDirPinA, direction pin A                                */
/* @param: MotorDirPinB, direction pin B                                */
/* return : void			                                            */
/* Description:set motor pins direction by writing IN or OUT on pins    */
/************************************************************************/
void DC_Motor_Init(uint8 MotorEnablePin,uint8 MotorDirPinA,uint8 MotorDirPinB)
{
	DIO_SetPinDirection(MotorEnablePin,OUT);
	DIO_SetPinDirection(MotorDirPinA,OUT);
	DIO_SetPinDirection(MotorDirPinB,OUT);
	
}


/************************************************************************/
/* Function: DC Motor move                                              */
/* @param: MotorEnablePin, enable pin for the motor                     */
/* @param: Dir_A, direction pin A				                        */
/* @param: Dir_B, direction pin B										*/
/* @param: Dir, direction to move forward or backward					*/
/* return : void			                                            */
/* Description:set motor direction to move forward or backward			*/
/************************************************************************/
void DC_MotorMove(uint8 MotorEnablePin,uint8 DIR_A,uint8 DIR_B, uint8 Dir)
{
	switch (Dir)
	{
		case MOTOR_FORWARD:
			if (DIO_ReadPin(DIR_A) == LOW && DIO_ReadPin(DIR_B) == HIGH ) /* check if the previous was backward make it stop first then reverse */
			{
				DIO_WritePin(DIR_B,LOW);
				_delay_ms(100); /* delay to slow down the motor */
			}
			DIO_WritePin(DIR_A,HIGH);
			DIO_WritePin(DIR_B,LOW);
			break;
		case MOTOR_BACKWARD:
			if (DIO_ReadPin(DIR_B) == LOW && DIO_ReadPin(DIR_A) == HIGH ) /* check if the previous was forward make it stop first then reverse */
			{
				DIO_WritePin(DIR_A,LOW);
				_delay_ms(100); /* delay to slow down the motor */
			}
			DIO_WritePin(DIR_B,HIGH);
			DIO_WritePin(DIR_A,LOW);
			break;
		case MOTOR_STOP:
			DIO_WritePin(MotorEnablePin,LOW);/* stop the motor by writing low on the enable pin */
			break;
	}
	
}
