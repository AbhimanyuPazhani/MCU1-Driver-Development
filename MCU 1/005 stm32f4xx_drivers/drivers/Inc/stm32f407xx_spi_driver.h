/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Nov 28, 2026
 *      Author: abhimanyu-0294
 */

#ifndef INC_STM32F407XX_SPI_DRIVER_H_
#define INC_STM32F407XX_SPI_DRIVER_H_

#include <stm32f407xx.h>

/*
 * This is a configuration structure for a SPIx Peripherals
 */

typedef struct
{
	uint8_t SPI_DeviceMode;			/*!< Possible values from  @GPIO_PIN_NUMBER >!*/
	uint8_t SPI_BusConfig;  			/*!< Possible values from  @GPIO_PIN_MODES >!*/
	uint8_t SPI_SclkSpeed; 			/*!< Possible values from  @GPIO_PIN_SPEEDS >!*/
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;


/*
 * Handles structure for SPIx Peripherals
 */
typedef struct
{

};

#endif /* INC_STM32F407XX_SPI_DRIVER_H_ */
