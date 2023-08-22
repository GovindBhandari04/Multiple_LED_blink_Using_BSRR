#include <stm32f4xx.h>
#define LED1  (1U<<1)
#define LED2  (1U<<2)
#define LED3  (1U<<3)
#define LED4  (1U<<4)
#define GPIOBEN  (1U<<1)

int main()
{
	RCC -> AHB1ENR |= GPIOBEN;

	GPIOB -> MODER |=(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8);
	GPIOB -> MODER &= ~(1U<<3) & ~(1U<<5) & ~(1U<<7) & ~(1U<<9);

	while(1)
	{
		GPIOB -> BSRR = LED1;
		GPIOB -> BSRR = LED2;
		GPIOB -> BSRR = LED3;
		GPIOB -> BSRR = LED4;
		for(int i=0;i<1000000;i++)
		{}

		GPIOB -> BSRR = (1<<17);
		GPIOB -> BSRR = (1<<18);
		GPIOB -> BSRR = (1<<19);
		GPIOB -> BSRR = (1<<20);
		for(int i=0;i<1000000;i++)
		{}
	}

	return 0;
}
