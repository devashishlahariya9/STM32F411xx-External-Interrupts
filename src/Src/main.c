#include "STM32F411xx_Interrupt.h"

#define pin 14
#define led 15

int main(void)
{
	NVIC_EnableIRQ(EXTI14_IRQ);
	GPIO_EnableIRQ(PORTA, pin, GPIO_FALLING);

	GPIO_setMode(PORTA, pin, LOW_SPEED, PUSH_PULL, AFIO);
	GPIO_setMode(PORTD, led, LOW_SPEED, PUSH_PULL, GPIO);

	while(1)
	{

	}
	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	GPIO_toggle(PORTD, led);

	GPIO_clearPendingIRQ(pin);
}
