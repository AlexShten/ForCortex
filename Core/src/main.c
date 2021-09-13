#include "stm32f4xx.h"

char flag = 0;
uint32_t counter = 0;


int main(void){

		//	enable PORTA, PORTD bus
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

		//	PORTD15
		//	MODER15[1:0] = 01 - General purpose output mode
		GPIOD->MODER &= ~GPIO_MODER_MODER15;
		GPIOD->MODER |= GPIO_MODER_MODER15_0;

		//	PORTA0
		//	MODER0[1:0] = 00 - General purpose input mode
		GPIOA->MODER &= ~GPIO_MODER_MODER0;

		//	OTYPER15 = 0 - Output push-pull
		GPIOD->OTYPER &= ~GPIO_OTYPER_OT_15;

		//	OSPEEDR15[1:0] = 00 - Low speed
		GPIOD->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED15;

		//	PUPDR15[1:0] = 00 - No pull-up, pull-down
		GPIOD->PUPDR &= ~GPIO_PUPDR_PUPDR15;

		//	PUPDR0[1:0] = 00 - Floating
		GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0;

		//	BSRR6 = 1 - clear bit
		GPIOD->BSRR |= GPIO_BSRR_BR15;


		while(1){
				while(counter < 300000) counter++;

				counter = 0;
				flag++;

				if((GPIOA->IDR & GPIO_IDR_IDR_0) == 0){
						if(flag % 2 == 0) GPIOD->BSRR |= GPIO_BSRR_BS15;
						else GPIOD->BSRR |= GPIO_BSRR_BR15;
				}
				else GPIOD->BSRR |= GPIO_BSRR_BR15;
		}
}
