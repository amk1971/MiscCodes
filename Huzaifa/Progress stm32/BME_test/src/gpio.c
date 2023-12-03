#include "stm32f1xx_hal.h"                  // Device header
#include <stdbool.h>
#include "gpio.h"

void GPIO_Reset(void)
{
	/**
	@brief  
	Resets specific bits in the GPIO registers prior to input or output mode
	configuration. PA13,PA14,PA15,PB2,PB3 and PB4 are left in their reset states.
	*/
	GPIOA->CRL &= ~0xCCCCCCCC;
	GPIOA->CRH &= ~0x000CCCCC;
	GPIOB->CRL &= ~0xCCC000CC;
	GPIOB->CRH &= ~0xCCCCCCCC;
	GPIOC->CRL &= ~0xCCCCCCCC;
	GPIOC->CRH &= ~0xCCCCCCCC;
}

	/**
	@brief Initializes GPIO peripheral to an output mode

	@param gpioPort: pointer to GPIO_TypeDef struct which contains
	all registers for the desired GPIO peripheral
	
	@param portLevel: The GPIO port configuration register is either low or high
	depending on the set of GPIO pins used. The port levels are GPIO_PORT_REG_LOW and  
	GPIO_PORT_REG_HIGH in the gpio.h file.
	
	@param mode: Configures the GPIO output mode speed e.g. if this parameter is passed
	with GPIO_PINx_OUTPUT_MODE_2MHZ, GPIO pin x is configured in output mode with a
	maximum speed of 2MHz. Multiple GPIO pins of the same port can be logically ORed
	to get their output mode configured.
	
	@param config: Configures the type of GPIO output e.g. general purpose push-pull,
	general purpose open-drain, alternate function push-pull and alternate function
	open-drain. If this parameter is passed with GPIO_PINx_ALT_FUNC_OPEN_DRAIN, 
	GPIO pin x will be configured as an alternate function output open drain pin.
	
	@return None
	
	*/
void GPIO_OutputInit(GPIO_TypeDef* gpioPort,
										 uint8_t portLevel,
										 uint32_t mode,
										 uint32_t config)

{
	volatile uint32_t* pGpioConfigReg = &gpioPort->CRL;
	
	if (portLevel == GPIO_PORT_REG_HIGH)
	{
		pGpioConfigReg = &gpioPort->CRH;
	}
	
	*pGpioConfigReg |= mode;
	*pGpioConfigReg |= config;
}
