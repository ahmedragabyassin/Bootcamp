/*
 * DCMotor.h
 *
 * Created: 2/21/2019 12:59:48 PM
 *  Author: AVE-LAP-057
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "Dio.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#include <util/delay.h>
#endif

/************************************************************************/
/* Definitions for motors pins                                          */
/************************************************************************/

#define MOTOR1_DIRECTION_A					PIN26				
#define MOTOR1_DIRECTION_B					PIN27
#define MOTOR2_DIRECTION_A					PIN30
#define MOTOR2_DIRECTION_B					PIN31
#define MOTOR1_ENABLE						PIN28
#define MOTOR2_ENABLE						PIN29

/************************************************************************/
/* Common used macros in DC motors                                      */
/************************************************************************/

#define MOTOR_FORWARD					0
#define MOTOR_BACKWARD					1
#define MOTOR_STOP						2



/************************************************************************/
/* fUNCTIONS PROTOTYPES                                                 */
/************************************************************************/



/************************************************************************/
/* Function: DC Motor Init                                              */
/* @param: MotorEnablePin, enable pin for the motor                     */
/* @param: MotorDirPinA, direction pin A                                */
/* @param: MotorDirPinB, direction pin B                                */
/* return : void			                                            */
/* Description:set motor pins direction by writing IN or OUT on pins    */
/************************************************************************/
void DC_Motor_Init(uint8 MotorEnablePin,uint8 MotorDirPinA,uint8 MotorDirPinB);



/************************************************************************/
/* Function: DC Motor move                                              */
/* @param: MotorEnablePin, enable pin for the motor                     */
/* @param: Dir_A, direction pin A				                        */
/* @param: Dir_B, direction pin B										*/
/* @param: Dir, direction to move forward or backward					*/
/* return : void			                                            */
/* Description:set motor direction to move forward or backward			*/
/************************************************************************/
void DC_MotorMove(uint8 MotorEnablePin,uint8 DIR_A,uint8 DIR_B, uint8 Dir);


/************************************************************************/
/* Function: DC Set Motor Direction                                     */
/* @param: Dir_A, direction pin A				                        */
/* @param: Dir_B, direction pin B										*/
/* @param: Dir, direction to move right or left							*/
/* return : void			                                            */
/* Description:set motor direction to move right or left				*/
/************************************************************************/
void DC_SetMotorDirection(uint8 Dir, uint8 DIR_A,uint8 DIR_B);



#endif /* DCMOTOR_H_ */