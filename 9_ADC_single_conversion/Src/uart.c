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


static void Uart_set_baudrate(USART_TypeDef *USARTX, uint32_t Periphclk, uint32_t BaudRate);
static uint16_t  compute_uart_bd(uint32_t Periphclk, uint32_t BaudRate);

void uart2_write(int ch);
void delay(volatile int time);


char uart2_read(void)
{
	/*Make sure that transmitting data register is empty*/

	while(!(USART2->SR & SR_RXE)){}

	return 	USART2->DR;


}

void uart2_write(int ch)
{
	/*Make sure that transmitting data register is empty*/

	while(!(USART2->SR & SR_TXE)){}

	/*Write to transmit data register*/
	USART2->DR = (ch & 0xFF);
}


void uart2_rxtx_init(void)
{
	/******Configuring the UART GPIO PIN******/
	/*Enable Clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;


	/*Set PA2 as mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |=(1<<5);



	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);



	/*Set PA3 as mode to alternate function mode*/

	GPIOA->MODER &=~(1U<<6);
	GPIOA->MODER |=(1<<7);


	/*Set PA3 alternate function type to UART_RX (AF07)*/
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);



	/******configur uart module******/
	/*Enable clock access to uart2*/
	RCC->APB1ENR |= UART2EN;


	/*Configure baudrate*/
	Uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/*configuring the transfer direction*/
	USART2->CR1 =  (CR1_TE | CR1_RE)	;

	/*enable uart module*/
	USART2->CR1 |= CR1_UE;

}


static void Uart_set_baudrate(USART_TypeDef *USARTX, uint32_t Periphclk, uint32_t BaudRate)
{
	USARTX->BRR = compute_uart_bd(Periphclk, BaudRate);
}


static uint16_t  compute_uart_bd(uint32_t Periphclk, uint32_t BaudRate)
{
	return ((Periphclk + (BaudRate/2U))/ BaudRate);
}


void delay(volatile int time)
{
    while(time--);
}


