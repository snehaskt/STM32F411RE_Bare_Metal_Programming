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

void uart2_rxtx_init(void);
void delay(volatile int time);
char uart2_read(void);
void uart2_write(int ch);



#endif /* UART_H_ */
