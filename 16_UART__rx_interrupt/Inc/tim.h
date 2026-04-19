/*
 * tim.h
 *
 *  Created on: Apr 5, 2025
 *      Author: hp
 */

#ifndef TIM_H_
#define TIM_H_

#include <stdint.h>

void tim2_1hz_init(void);
void tim2_PA5output_compare(void);
void tim3_input_capture(void);

#define SR_UIF				(1U<<0)
#define SR_CC1IF			(1U<<1)


#endif /* TIM_H_ */
