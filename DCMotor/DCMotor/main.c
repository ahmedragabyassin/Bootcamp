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
    TimerOneInit();
	DC_Motor_Init(MOTOR1_ENABLE,MOTOR1_DIRECTION_A,MOTOR1_DIRECTION_B);
	DC_MotorMove(MOTOR1_ENABLE,MOTOR1_DIRECTION_A,MOTOR1_DIRECTION_B,MOTOR_BACKWARD);
	DC_Motor_Init(MOTOR2_ENABLE,MOTOR2_DIRECTION_A,MOTOR2_DIRECTION_B);
	DC_MotorMove(MOTOR2_ENABLE,MOTOR2_DIRECTION_A,MOTOR2_DIRECTION_B,MOTOR_FORWARD);
    while (1) 
    {
    }
}

