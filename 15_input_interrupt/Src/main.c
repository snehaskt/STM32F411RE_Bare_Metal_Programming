#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"


#define GPIOAEN				(1U<<0)
#define PIN					(1U<<5)
#define LED_PIN				PIN

volatile bool uart_tx_flag = false;
void send_uart_message(const char *msg);
static void exti_callback(void);
void EXTI15_10_IRQHandler(void);
void delay(volatile int time);


int main(void)
{
	/*Enable the clock access to the GPIOA*/
		RCC-> AHB1ENR |= GPIOAEN;


		/*set PA5 as the out pin*/
		GPIOA-> MODER |= (1U<<10);
		GPIOA-> MODER &= ~(1U<<11);


		uart2_rxtx_init();
		pc13_exti_init();



	while(1)
	{
		if(uart_tx_flag)
		{
			uart_tx_flag = false;
			send_uart_message("Button pressed....\r\n");
		}


	}

}


static void exti_callback(void)
{
	//printf("B\n\r");
	GPIOA -> ODR ^= LED_PIN;

	//set flag to send UART message in main loop
	uart_tx_flag = true;
}


void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & LINE13) != 0)
	{
		/*CLERA THE PR FLAG*/
		EXTI->PR |= LINE13; // checking the pending register bit 13
		/*DO SOMETHING...*/
		exti_callback();

	}

}
