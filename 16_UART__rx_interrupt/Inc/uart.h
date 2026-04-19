 /*
 * uart.h
 *
 *  Created on: Feb 13, 2025
 *      Author: hp
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include "stm32f4xx.h"

//void uart2_rxtx_init(void);
//void delay(volatile int time);
char uart2_read(void);
//void uart2_write(int ch);


void uart2_rxtx_init(void);

void uart2_write(char ch);
void send_uart_message(const char *msg);
void uart2_rx_init(void);
void uart2_rx_interrupt_init(void);





#endif /* UART_H_ */
