/*
 * uart.c
 *
 * Created on: Feb 13, 2025
 *      Author: hp
 */


#include "uart.h"

#define GPIOAEN     (1U << 0)
#define UART2EN     (1U << 17)

#define CR1_TE      (1U << 3)
#define CR1_RE      (1U << 2)
#define CR1_UE      (1U << 13)
#define SR_TXE      (1U << 7)

#define SYS_FREQ        16000000
#define APB1_CLK        SYS_FREQ
#define UART_BAUDRATE   115200

void uart2_write(char ch);
void uart2_write_string(char *str);

void uart2_rxtx_init(void)
{
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set PA2 to alternate function mode (AF7 - USART2_TX) */
    GPIOA->MODER &= ~(3U << 4);    // Clear bits
    GPIOA->MODER |=  (2U << 4);    // Set to AF mode
    GPIOA->AFR[0]  &= ~(0xFU << 8);
    GPIOA->AFR[0]  |=  (7U << 8);

    /* Set PA3 to alternate function mode (AF7 - USART2_RX) */
    GPIOA->MODER &= ~(3U << 6);
    GPIOA->MODER |=  (2U << 6);
    GPIOA->AFR[0]  &= ~(0xFU << 12);
    GPIOA->AFR[0]  |=  (7U << 12);

    /* Enable clock access to USART2 */
    RCC->APB1ENR |= UART2EN;

    /* Set baudrate */
    USART2->BRR = APB1_CLK / UART_BAUDRATE;

    /* Enable TX and RX */
    USART2->CR1 |= (CR1_TE | CR1_RE);

    /* Enable USART2 */
    USART2->CR1 |= CR1_UE;
}

void uart2_write(char ch)
{
    /* Wait until TXE is set */
    while (!(USART2->SR & SR_TXE));
    USART2->DR = (ch & 0xFF);  // Ensure only 8 bits are written
}

void uart2_write_string(char *str)
{
    while (*str)
    {
        uart2_write(*str++);
    }
}

