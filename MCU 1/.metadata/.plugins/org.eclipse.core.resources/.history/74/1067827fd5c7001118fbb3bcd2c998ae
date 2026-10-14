/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Jul 14, 2026
 *      Author: CITI
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include <stm32f407xx.h>

/*
 * This is a configuration structure for a  GPIO pin
 */

typedef struct
{
	uint8_t GPIO_PinNumber;			/*!< Possible values from  @GPIO_PIN_NUMBER >!*/
	uint8_t GPIO_PinMode;  			/*!< Possible values from  @GPIO_PIN_MODES >!*/
	uint8_t GPIO_PinSpeed; 			/*!< Possible values from  @GPIO_PIN_SPEEDS >!*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */



typedef struct
{
	//Pointer to hold the base address of the GPIO Peripherals
	GPIO_RegDef_t *pGPIOx; /* This holds the base address of the GPIO port to which the pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig; //This holds the GPIO pin configuration settings

}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBER
 * GPIO Pin Numbers
 */
#define GPIO_PIN_NO_0 		0
#define GPIO_PIN_NO_1 		1
#define GPIO_PIN_NO_2 		2
#define GPIO_PIN_NO_3 		3
#define GPIO_PIN_NO_4 		4
#define GPIO_PIN_NO_5 		5
#define GPIO_PIN_NO_6 		6
#define GPIO_PIN_NO_7 		7
#define GPIO_PIN_NO_8 		8
#define GPIO_PIN_NO_9 		9
#define GPIO_PIN_NO_10 		10
#define GPIO_PIN_NO_11 		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13 		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15 		15

/*
 * @GPIO_PIN_MODES
 * GPIO Pin Possible modes
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT		4    //IT = Input; FT = Falling Edge or time.
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT	6    //RFT = Rising/falling Edge


/*
 * GPIO Pin Possible OUTPUT types
 */
#define GPIO_OP_TYPE_PP		0 //PP = Push Pull
#define GPIO_OP_TYPE_OD		1 //OD = Open Drain

/*
 * @GPIO_PIN_SPEEDS
 * GPIO Pin Possible OUTPUT SPEEDS
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*
 * GPIO pin PULL UP and PULL DOWN configuration Macros
 */
#define GPIO_NO_PUPD 		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2




/*************************************************************************************
 * 								API supported by this driver
 * 			For more information about the APIs check the function definitions
 **************************************************************************************/
/*
 * Peripheral Clock Setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Date read and write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOuputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ configuration and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
