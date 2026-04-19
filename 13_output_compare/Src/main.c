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

	tim2_1hz_init();
	tim2_PA5output_compare();

	while(1)
	{


	}

}
