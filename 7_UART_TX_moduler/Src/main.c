#include <stdint.h>
#include "stm32f4xx.h"
#include "uart.h"


int main(void)
{
	uart2_tx_init();

	while(1)
	{
		uart2_write('Y');
        delay(100000);  // Add a delay to slow down transmission
	}
}


