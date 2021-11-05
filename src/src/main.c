#include "STM32F411xx_Interrupt.h"

#define pin 14
#define led 13

int main(void)
{
	enableIRQ(EXTI14_IRQ);
	GPIO_Enable_IRQ(PORTA, pin, FALLING);

	GPIO_setMode(PORTA, pin, LOW_SPEED, PUSH_PULL, AFIO);
	GPIO_setMode(PORTB, led, LOW_SPEED, PUSH_PULL, GPIO);

	while(1)
	{

	}
	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	GPIOB -> ODR ^= (1 << led);

	EXTI -> PR |= (1 << pin);
}
