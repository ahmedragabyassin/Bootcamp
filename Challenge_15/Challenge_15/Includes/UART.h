/*
 * UART.h
 *
 * Created: 2/27/2019 1:47:19 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef UART_H_
#define UART_H_

#include "types.h"
#include "BitwiseOperations.h"
#include "CommonNumbers.h"
/*  main struct that configring all data */
typedef struct  {
	uint32 BaudRate ;
	uint8 No_StopBits ;
	uint8 ParityMode ;
	uint8 DataSize ;
	uint8 SpeedMode ;
}UART_Config_S ;


/**************************************************************************************************/
/*Function Name :- UART_init                                                                      */
/*Function job   :- initializing Uart module                                                      */
/*Function inputs :- baud rate                                                                    */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/
void UART_Init(void);

/**************************************************************************************************/
/*Function Name :- UART_sendByte                                                                  */
/*Function job   :- sending byte bu uart                                                          */
/*Function inputs :- sending character                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/


void UART_Transmit(uint8 data);

/**************************************************************************************************/
/*Function Name :- UART_receiveByte                                                               */
/*Function job   :-receiving byte by uart                                                         */
/*Function inputs :- N/A                                                                          */
/*Function outputs :-byte recievied                                                               */
/**************************************************************************************************/
uint8 UART_receive(void);


void UART_TransmitString(uint8 *String,uint8 size);

#endif /* UART_H_ */