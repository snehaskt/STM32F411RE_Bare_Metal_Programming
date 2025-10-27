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


int timestamp = 0;

int main(void)
{

	tim2_1hz_init();
	tim2_PA5output_compare();
	tim3_input_capture();


	while(1)
	{
		/*Wait until the edge is completed*/
		while(!(TIM3->SR & SR_CC1IF)){}

		/*read capture*/
		timestamp = TIM3->CCR1;
	}

}
