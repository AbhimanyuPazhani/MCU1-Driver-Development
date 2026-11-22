/*
 * main.c
 *
 *  Created on: Nov 21, 2026
 *      Author: abhimanyu-0294
 */


#include "stm32f407xx.h"

int main(void)
{
	return 0;
}

void EXTI0_IRQHandler (void)
{
	//Handle the interrupt
	GPIO_IRQHandling(0);
}
