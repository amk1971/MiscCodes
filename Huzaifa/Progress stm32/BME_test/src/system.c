#include "stm32f1xx_hal.h"                  // Device header
#include <stdbool.h>
#include "clocks.h"
#include "gpio.h"
#include "system.h"
#include "../systick.h"

/**
@brief Initializes all necessary peripherals of the microcontroller
*/
void System_Init(void)
{
	Clocks_Init();
	//SysTick_Init();
	GPIO_Reset();
}

//void HAL_Delay(uint32_t milliseconds);
