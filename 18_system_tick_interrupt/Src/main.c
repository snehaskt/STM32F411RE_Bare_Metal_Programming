#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"


#define GPIOAEN				(1U<<0)
#define PIN					(1U<<5)
#define LED_PIN				PIN

static void systick_callback();
int main(void)
{

	/*Enable the clock access to the GPIOA*/
	RCC-> AHB1ENR |= GPIOAEN;


	/*set PA5 as the out pin*/
	GPIOA-> MODER |= (1U<<10);
	GPIOA-> MODER &= ~(1U<<11);


	uart2_rxtx_init();
	systick_1hz_interrupt();


	while(1)
	{
		/*Toggle the LED*/
		uart2_write_string("second passed\n\r");
		GPIOA-> ODR ^= LED_PIN;
	}

}

static void systick_callback()
{
	uart2_write_string("second passed\n\r");
	GPIOA-> ODR ^= LED_PIN;
}

void SysTick_Handler(void)
{
	/*Do something over here*/
	systick_callback();
}



