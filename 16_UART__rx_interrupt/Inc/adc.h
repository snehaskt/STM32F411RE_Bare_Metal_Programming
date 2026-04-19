/*
 * adc.h
 *
 *  Created on: Feb 22, 2025
 *      Author: hp
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void pa1_adc_init(void);
uint32_t adc_read (void);
void start_conversion (void);


#endif /* ADC_H_ */
