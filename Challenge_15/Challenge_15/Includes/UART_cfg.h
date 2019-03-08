/*
 * UART_cfg.h
 *
 * Created: 2/27/2019 1:22:26 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

#define FALSE			0
#define TRUE			1

/* entered by user */
#define BAUDRATE		9600
#define NO_STOPBITS		1
#define PARITYMODE  FALSE
#define DATASIZE    eight_bit
#define SPEEDMODE   ON
#define  ON 1
#define  OFF 0

#define F_CPU 16000000
/* memory mapping of uart  */
#define UCSRC (*((volatile uint8 *)(0x40)))
#define UBRRH (*((volatile uint8 *)(0x40)))
#define UDR (*((volatile uint8 *)(0x2C)))
#define UCSRA (*((volatile uint8 *)(0x2B)))
#define UCSRB (*((volatile uint8 *)(0x2A)))
#define UBRRL (*((volatile uint8 *)(0x29)))

#define UCSZ0  1
#define UCSZ1 2
#define UCSZ2 2
#define URSEL 7
#define TXEN  3
#define RXEN 4
#define U2X 1
#define UDRE 5
#define TXC 6
#define RXC 7
#define USBS 3
#define UPM0 4
#define UPM1 5
#define even 1
#define  odd 2

#define six_bit 6
#define seven_bit 7
#define eight_bit 8
#define nine_bit 9





#endif /* UART_CFG_H_ */