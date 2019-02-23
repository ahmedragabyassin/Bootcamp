/*
 * DCMotor.c
 *
 * Created: 2/21/2019 12:03:09 PM
 * Author : AVE-LAP-057
 */ 

#include "Includes/Timer.h"
#include "Includes/DCMotor.h"


int main(void)
{
	
	#if ENABLE_CODE
	/************************************************************************/
	/* Initialize timer 1 in PWM and initialize motors in direction         */
	/************************************************************************/
    TimerOneInit(DUTY_25);
	_delay_ms(ONE_1000_MS);
	/* Motor 1 */
	DC_Motor_Init(MOTOR1_ENABLE,MOTOR1_DIRECTION_A,MOTOR1_DIRECTION_B);
	DC_MotorMove(MOTOR1_ENABLE,MOTOR1_DIRECTION_A,MOTOR1_DIRECTION_B,MOTOR_BACKWARD);
	/* motor 2*/
	DC_Motor_Init(MOTOR2_ENABLE,MOTOR2_DIRECTION_A,MOTOR2_DIRECTION_B);
	DC_MotorMove(MOTOR2_ENABLE,MOTOR2_DIRECTION_A,MOTOR2_DIRECTION_B,MOTOR_FORWARD);
	TimerOneInit(DUTY_50);
	_delay_ms(ONE_1000_MS);
	TimerOneInit(DUTY_75);
	_delay_ms(ONE_1000_MS);
	TimerOneInit(DUTY_100);
	_delay_ms(ONE_1000_MS);
	#endif
    while (NUM_1) 
    {
    }
}

