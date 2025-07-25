#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

#define LIGHT_THRESHOLD 2000  // Adjust based on LDR calibration (12-bit ADC: 0–4095)

uint32_t sensor_value;

int main(void)
{
    uart2_rxtx_init();
    pa1_adc_init();

    char buffer[50];

    while (1)
    {
        start_conversion();
        sensor_value = adc_read();

        // Convert ADC value to string and print
        sprintf(buffer, "Sensor value: %lu\r\n", sensor_value);
        uart2_write_string(buffer);

        if (sensor_value > LIGHT_THRESHOLD)
        {
            uart2_write_string("Light is ON\r\n");
        }
        else
        {
            uart2_write_string("Light is OFF\r\n");
        }

        for (volatile int i = 0; i < 10000000; i++); // Delay
    }
}

