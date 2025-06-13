//where is the led connected?
//port: A
//pin : 5
#include <stdint.h>
#define PERIPH_BASE		                       (0X40000000UL)
#define AHB1PERIPH_OFFSET		               (0X00020000UL)
#define AHB1PERIPH_BASE                        (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET	                       (0X0000UL)
#define GPIOA_BASE		                       (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define RCC_OFFSET                             (0x3800UL)
#define RCC_BASE                               (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN                                (1U<<0)
#define PIN5                                   (1U<<5)
#define LED_PIN                                  PIN5


typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;

}RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;
}GPIOA_TypeDef;



#define RCC			((RCC_TypeDef*) RCC_BASE)
#define	GPIOA		((GPIOA_TypeDef*)GPIOA_BASE)



int main(void)
{
	/* Enable clock access to GPIOA*/

	RCC->AHB1ENR |= GPIOAEN;
	/* 2.set PA5 as output pin*/


	GPIOA->MODER |= (1U<<10); //SET bit 10 to 1
	GPIOA->MODER  &=~(1U<<11); //set bit 11 to 0
	while (1)
	{

		GPIOA -> ODR ^= LED_PIN;

		for(int i=0; i<10000000; i++){}
	}

}
