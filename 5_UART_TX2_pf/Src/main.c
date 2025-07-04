#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"


#define GPIOAEN            (1U<<0)
#define UART2EN            (1U<<17)

// USART CR1 TE (transmit enable bit)
#define CR1_TE             (1U<<3)

// USART CR1 UE (UART enable bit) - bit 13
#define CR1_UE             (1U<<13)

// USART SR_TXE (status register - TX empty) - bit 7
#define SR_TXE             (1U<<7)

// System frequency and APB1 clock
#define SYS_FREQ           16000000
#define APB1_CLK           SYS_FREQ

#define UART_BAUDRATE      115200

static void Uart_set_baudrate(USART_TypeDef *USARTX, uint32_t Periphclk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t Periphclk, uint32_t BaudRate);

void uart2_tx_init(void);
void uart2_write(int ch);
void delay(volatile int time);

int _io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

int main(void)
{
    uart2_tx_init();

    while(1)
    {
    	//uart2_write('W');
       printf("HEllO stm32f4\n\r");
       delay(100000);  // Add a delay to slow down transmission
    }
}

void uart2_write(int ch)
{
    /* Make sure that transmitting data register is empty */
    while (!(USART2->SR & SR_TXE)) {}

    /* Write to transmit data register */
    USART2->DR = (ch & 0xFF);
}
void uart2_tx_init(void)
{
    /****** Configuring the UART GPIO PIN ******/
    /* Enable Clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set PA2 as mode to alternate function mode */
    GPIOA->MODER &= ~(1U<<4);
    GPIOA->MODER |= (1<<5);

    /* Set PA2 alternate function type to UART_TX (AF07) */
    GPIOA->AFR[0] &= ~(0xF << 8);   // Clear the previous setting (4 bits for PA2)
    GPIOA->AFR[0] |= (7 << 8);      // Set AF7 (UART_TX)

    /****** Configure UART module ******/
    /* Enable clock access to UART2 */
    RCC->APB1ENR |= UART2EN;

    /* Configure baudrate */
    Uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

    /* Configuring the transfer direction */
    USART2->CR1 = CR1_TE;

    /* Enable UART module */
    USART2->CR1 |= CR1_UE;
}

static void Uart_set_baudrate(USART_TypeDef *USARTX, uint32_t Periphclk, uint32_t BaudRate)
{
    USARTX->BRR = compute_uart_bd(Periphclk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t Periphclk, uint32_t BaudRate)
{
    uint32_t div = (Periphclk * 100U) / BaudRate;
    uint32_t mantissa = div / 100U;  // Dividing by 100 gives the integer part
    uint32_t fraction = div - (mantissa * 100U);  // The fractional part
    return (mantissa << 4) | (fraction / 16U);  // Shift mantissa to upper 12 bits, fraction to lower 4 bits
}

void delay(volatile int time)
{
    while(time--);
}
