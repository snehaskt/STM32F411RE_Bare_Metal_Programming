/*
 * uart.c
 *
 * Created on: Feb 13, 2025
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


//static void Uart_set_baudrate(USART_TypeDef *USARTX, uint32_t Periphclk, uint32_t BaudRate);
//static uint16_t  compute_uart_bd(uint32_t Periphclk, uint32_t BaudRate);
void uart2_write(char ch);
//void delay(volatile int time);
//char uart2_read(void);



void uart2_rxtx_init(void)
{
    // Enable GPIOA clock
    RCC->AHB1ENR |= GPIOAEN;

    // Configure PA2 as AF7 (UART2 TX)
    GPIOA->MODER &= ~(3U << 4);
    GPIOA->MODER |= (2U << 4);
    GPIOA->AFR[0] &= ~(0xF << 8);
    GPIOA->AFR[0] |= (7U << 8);


    // Configure PA3 as AF7 (UART2 RX)
       GPIOA->MODER &= ~(3U << 6);
       GPIOA->MODER |= (2U << 6);
       GPIOA->AFR[0] &= ~(0xF << 12);
       GPIOA->AFR[0] |= (7U << 12);

       // Enable UART2 clock
       RCC->APB1ENR |= UART2EN;

       // Configure baud rate (assuming 16 MHz APB1)
       USART2->BRR = 16000000 / 115200;

       // Enable transmitter and receiver
       USART2->CR1 = (1 << 3) | (1 << 2);

       // Enable UART
       USART2->CR1 |= (1 << 13);

   }

   void uart2_write(char ch)
   {
       // Wait until transmit data register empty
       while(!(USART2->SR & (1 << 7))) {}
       USART2->DR = ch;
   }

   void send_uart_message(const char *msg)
   {
       while(*msg)
       {
           uart2_write(*msg++);
       }
   }

