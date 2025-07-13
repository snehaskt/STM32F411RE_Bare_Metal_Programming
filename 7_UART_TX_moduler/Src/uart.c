/*
 * uart.c
 *
 *  Created on: Feb 13, 2025
 *      Author: hp
 */



#include "uart.h"

#define GPIOAEN				(1U<<0)
#define UART2EN				(1U<<17)


//usart_cr1 TE(transmitting bit)
#define CR1_TE				(1U<<3)

//usart_cr1 RE(receiving bit)
#define CR1_RE				(1U<<2)

//usart_cr1 UE(uart enable)- bit 13
#define CR1_UE				(1U<<13)

//usart SR_TXE(status register) - bit7
#define SR_TXE				(1U<<7)

//usart SR_RXE(status register) - bit5
#define SR_RXE				(1U<<5)

//setting the system frequency
#define SYS_FREQ			16000000
#define APB1_CLK			SYS_FREQ

#define UART_BAUDRATE		115200




void uart2_write(int ch)
{
	/*Make sure that transmitting data register is empty*/

	while(!(USART2->SR & SR_TXE)){}

	/*Write to transmit data register*/
	USART2->DR = (ch & 0xFF);
}

void uart2_tx_init(void)
{
    // Enable GPIOA clock
    RCC->AHB1ENR |= GPIOAEN;

    // Configure PA2 as AF7 (UART2 TX)
    GPIOA->MODER &= ~(3U << 4);
    GPIOA->MODER |= (2U << 4);
    GPIOA->AFR[0] &= ~(0xF << 8);
    GPIOA->AFR[0] |= (7U << 8);

       // Enable UART2 clock
       RCC->APB1ENR |= UART2EN;

       // Configure baud rate (assuming 16 MHz APB1)
       USART2->BRR = 16000000 / 115200;

       // Enable transmitter and receiver
       USART2->CR1 = (1 << 3) | (1 << 2);

       // Enable UART
       USART2->CR1 |= (1 << 13);

   }

   void send_uart_message(const char *msg)
   {
       while(*msg)
       {
           uart2_write(*msg++);
       }
   }


   void delay(volatile int time)
   {
       while(time--);
   }

