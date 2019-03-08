/*
 * UART.h
 *
 * Created: 2/27/2019 1:12:24 PM
 *  Author: AVE-LAP-023
 */ 

#include "../Includes/UART_cfg.h"
#include "../Includes/UART.h"

/**************************************************************************************************/
/*Function Name :- UART_init                                                                      */
/*Function job   :- initializing Uart module                                                      */
/*Function inputs :- baud rate                                                                    */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/

void UART_Init(void)
{
	uint16 UBRR ; /* declare a variable to stor baud rate */
	/* initializing struct */
	UART_Config_S U1 = {BAUDRATE,NO_STOPBITS,PARITYMODE,DATASIZE,SPEEDMODE};
		/* inserting number of stop bits */
		if(NUM_2 == U1.No_StopBits){
			UCSRC |= (TRUE<<USBS);
		}
		else {
			
		}
		/* choosing parity mode */
		switch (U1.ParityMode){
			case even : UCSRC |= (TRUE<<UPM1);
			break;
			case  odd : UCSRC |= (TRUE<<UPM1) | (TRUE<<UPM0);
			break;
		}
		/* choosing character size */
		switch(U1.DataSize){
			case six_bit : UCSRC |= (TRUE<<UCSZ0);
			break ;
			case seven_bit : UCSRC |= (TRUE<<UCSZ1);
			break ;
			case eight_bit : UCSRC |= (TRUE<<UCSZ0) | (TRUE<<UCSZ1);
			break ;
			case nine_bit : UCSRC |= (TRUE<<UCSZ0) | (TRUE<<UCSZ1);
			UCSRB |= (TRUE<<UCSZ2);
			break ;
			
		}
	/* using double speed transmission option  */
	if(ON == U1.SpeedMode){
	 UCSRA |= (TRUE<<U2X);
	  /* equation of baud rate  */
	  UBRR = (F_CPU/(eight_bit*U1.BaudRate))-TRUE;
	}
	else{
		 UBRR = (F_CPU/(NUM_16 * U1.BaudRate))-TRUE;
	}
	 /* enabling receiving and transmitting bits */
	 UCSRB |= (TRUE<<RXEN) | (TRUE<<TXEN) ;
	 /* choosing 8-bit data frame by setting bit 0 & 1 */
	 UCSRC |= (TRUE<<URSEL) | (TRUE<<UCSZ0) | (TRUE<<UCSZ1) ;
	/* entering baud rate */
	 UBRRH = UBRR >> eight_bit;
	 UBRRL = UBRR ;
}


/**************************************************************************************************/
/*Function Name :- UART_sendByte                                                                  */
/*Function job   :- sending byte bu uart                                                          */
/*Function inputs :- sending character                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/


void UART_Transmit(uint8 data)
{
	/* polling until flag is set then clear it by writing 1 */
	while(!GET_BIT(UCSRA,UDRE));
	/* sending 1 byte through data register */
	UDR = data ;
	
/*	while(!(Get_Bit(UCSRA,TXC)));
	Set_Bit(UCSRA,TXC);*/
	
}

/**************************************************************************************************/
/*Function Name :- UART_receiveByte                                                               */
/*Function job   :-receiving byte by uart                                                         */
/*Function inputs :- N/A                                                                          */
/*Function outputs :-byte receivied                                                               */
/**************************************************************************************************/


uint8 UART_receive(void)
{
	/* polling until flag is set then clear it by writing 1 */
	while(!GET_BIT(UCSRA,RXC));
	/* receiving 1 byte through data register */
	 return UDR; 
	
}

/**************************************************************************************************/
/*Function Name :- UART_TransmitString                                                              */
/*Function job   :- sending string by uart                                                          */
/*Function inputs :- sending string                                                            */
/*Function outputs :- N/A                                                                         */
/**************************************************************************************************/


void UART_TransmitString(uint8 *String,uint8 size)
{
	uint8 count = FALSE; /* counting variable of pointer */
	/* sending data byte by byte till null character */
	for(count=FALSE;count<size;count++)
	{
		UART_Transmit(String[count]);
	}
	
}

