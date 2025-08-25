 #include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"


#define GPIOAEN				(1U<<0)
#define PIN					(1U<<5)
#define LED_PIN				PIN



int main(void)
{
	/*Enable the clock access to the GPIOA*/
		RCC-> AHB1ENR |= GPIOAEN;


		/*set PA5 as the out pin*/
		GPIOA-> MODER |= (1U<<10);
		GPIOA-> MODER &= ~(1U<<11);

	    uart2_rxtx_init();
	    tim2_1hz_init();



	while(1)
	{
		/*Wait for UIF (update interrupt flag)*/
		while(!(TIM2->SR & SR_UIF)) {}

		/*Clear UIF*/
		TIM2->SR &= ~SR_UIF;
		uart2_write_string("second passed LED ON!\n\r");

		/*Toggle the LED*/
		GPIOA -> ODR ^= LED_PIN;

	}

}
