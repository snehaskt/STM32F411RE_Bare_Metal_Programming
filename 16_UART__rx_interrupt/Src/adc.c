#include "adc.h"
#include "stm32f4xx.h"
#include <stdint.h>


#define GPIOAEN					(1U<<0)
#define ADC1EN					(1U<<8)
#define ADC_CH1					(1U<<0)
#define ADC_SEQ_LEN_1 			0X00
#define CR2_ADON				(1U<<0)
#define CR2_SWSTART				(1U<<30)
#define CR2_CONT				(1U<<1)


/* SR_EOC-status register end of conversion*/
/* after end of conversion only we have to set the SR_EOC or else it will not display the result*/
#define SR_EOC					(1U<<1)


//ADC1 is a 16 channel analog inputs it is connected to APB2 bus.

// ADC1_1 this refers that ADC1 is having 3 channels 1,2&3 but we
// are connecting to the channel 1 so 1 is connected to PA1.

void pa1_adc_init(void)
{
	/*****configure the ADC GPIO pin*****/

	/**Enable clock access to the GPIOA**/
	RCC->AHB1ENR |= GPIOAEN;

	/*set the mode of pa1 to analog mode*/
	// pin1
	// bit 2, bit 3 [11] - analog mode

	GPIOA -> MODER |= (1U<<2);
	GPIOA -> MODER |= (1U<<3);


	/*****configuring the ADC module*****/

	/*Enable clock access to ADC*/

	RCC->APB2ENR |= ADC1EN;

	/*****configure the adc parameter*****/

	/*conversion sequence start*/


	/*ADC configured with 3 channels.
	 * first = ch5
	 * second = ch3
	 * third = ch2
	 * */

	ADC1 -> SQR3 |= ADC_CH1;

	/*conversion sequence length*/

	ADC1->SQR1 = ADC_SEQ_LEN_1;

	/*Enable ADC module*/
	// Bit 0 ADON: A/D Converter ON / OFF
	//This bit is set and cleared by software.
	//Note: 0: Disable ADC conversion and go to power down mode
	//      1: Enable ADC

	ADC1->CR2 = CR2_ADON;

}


void start_conversion (void)
{

	/*Enable continuous conversion mode*/
	ADC1->CR2 |= CR2_CONT;

	/*start ADC conversion*/
	//Bit 30 SWSTART: Start conversion of regular channels
	//This bit is set by software to start conversion and cleared by hardware as soon as the
	//conversion starts.
	//0: Reset state
	//1: Starts conversion of regular channels
	//Note: This bit can be set only when ADON = 1 otherwise no conversion is launched


	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read (void)
{
	//Bit 1 EOC: Regular channel end of conversion
	//This bit is set by hardware at the end of the conversion of a regular group of channels. It is
	//cleared by software or by reading the ADC_DR register.
	//0: Conversion not complete (EOCS=0), or sequence of conversions not complete (EOCS=1)
	//1: Conversion complete (EOCS=0), or sequence of conversions complete (EOCS=1)

	//it will return the true or false if the conversion completed true and continue for next line.
	// if it false check untill it write true.


	while(!(ADC1->SR & SR_EOC)){}

	/* return adc_read*/

	return (ADC1-> DR);

}


