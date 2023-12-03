#ifndef _GPIO_H
#define _GPIO_H

enum PortRegLevel
{
	GPIO_PORT_REG_LOW = 0,
	GPIO_PORT_REG_HIGH = 1
};

#define GPIO_PULLUP_ENABLE										true
#define GPIO_GEN_PUR_OUTPUT_PUSH_PULL					0x00

#define GPIO_PIN6					  									6
#define GPIO_PIN6_OUTPUT_MODE_2MHZ						GPIO_CRL_MODE6_1
#define GPIO_PIN6_INPUT_PULLUP_OR_PULLDOWN 	  GPIO_CRL_CNF6_1
#define GPIO_PIN6_ALT_FUNC_OPEN_DRAIN					GPIO_CRL_CNF6

#define GPIO_PIN7					  									7
#define GPIO_PIN7_ALT_FUNC_OPEN_DRAIN					GPIO_CRL_CNF7
#define GPIO_PIN7_OUTPUT_MODE_2MHZ						GPIO_CRL_MODE7_1
#define GPIO_PIN7_ALT_FUNC_PUSH_PULL					GPIO_CRL_CNF7_1

//Resets GPIO port configuration register bits
extern void GPIO_Reset(void);

//Initializes the GPIO to the output mode of choice
extern void GPIO_OutputInit(GPIO_TypeDef* gpioPort,
														uint8_t portLevel,
														uint32_t mode,
														uint32_t config);


#endif //_GPIO_H
