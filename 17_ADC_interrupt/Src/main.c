
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

#define LIGHT_THRESHOLD 2000  // Adjust based on testing (for 12-bit ADC: 0–4095)

uint32_t sensor_value;

int main(void)
{


	uart2_rxtx_init();
	pa1_adc_init();

	while(1)
	{
		start_conversion();
		sensor_value = adc_read();
		printf("Sensor value:%d\n\r", (int)sensor_value);

		//uint16_t adc_value = adc_read(); // Read ADC value

		        if(sensor_value > LIGHT_THRESHOLD)
		        {
		            uart2_write("Light is ON\r\n");
		        }
		        else
		        {
		            uart2_write("Light is OFF\r\n");
		        }

		        for (volatile int i = 0; i < 100000; i++); // Delay
		    }
}

