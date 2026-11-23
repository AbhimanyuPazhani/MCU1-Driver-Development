/*
 * stm32f407xx.h
 *
 *  Created on: Jul 2, 2026
 *      Author: CITI
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#define __vo 					volatile

/************************START:  Processor specific details *******************************/
/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */
#define NVIC_ISER0 		((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1 		((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2 		((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3 		((__vo uint32_t*)0xE000E10C)

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER0 		((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1 		((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2 		((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3 		((__vo uint32_t*)0xE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register  Adderess calculation
 */
#define NVIC_PR_BASE_ADDR 		((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor No of priority bits implemented in priority register
 */
#define NO_PR_BITS_IMPLEMENTED  4

//Base address of Flash and SRAM
#define FLASH_BASEADDR    		0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x20001C00U
#define ROM_BASEADDR			0x1FFF0000U
#define SRAM					SRAM1_BASEADDR

//AHBx and APBx Bus peripheral base addresses

#define PERIPH_BASE				0X40000000U
#define APB1PERIPH_BASE			PERIPH_BASE
#define APB2PERIPH_BASE			0X40010000U
#define AHB1PERIPH_BASE			0X40020000U
#define AHB2PERIPH_BASE 		0X50000000U

//Base addresses of peripherals which are hanging on the AHB1 bus

#define GPIOA_BASEADDR 			(AHB1PERIPH_BASE + 0X0000)
#define GPIOB_BASEADDR 			(AHB1PERIPH_BASE + 0X0400)
#define GPIOC_BASEADDR 			(AHB1PERIPH_BASE + 0X0800)
#define GPIOD_BASEADDR 			(AHB1PERIPH_BASE + 0X0C00)
#define GPIOE_BASEADDR 			(AHB1PERIPH_BASE + 0X1000)
#define GPIOF_BASEADDR 			(AHB1PERIPH_BASE + 0X1400)
#define GPIOG_BASEADDR 			(AHB1PERIPH_BASE + 0X1800)
#define GPIOH_BASEADDR 			(AHB1PERIPH_BASE + 0X1C00)
#define GPIOI_BASEADDR 			(AHB1PERIPH_BASE + 0X2000)
//#define GPIOJ_BASEADDR 			(AHB1PERIPH_BASE + 0X2400) (available on high-pin-count devices like STM32F429/439)
//#define GPIOK_BASEADDR 			(AHB1PERIPH_BASE + 0X2800) (available on high-pin-count devices like STM32F429/439)

#define RCC_BASEADDR			(AHB1PERIPH_BASE + 0X3800)

//Base addresses of peripherals which are hanging on the APB1 bus.
#define I2C1_BASEADDR			(APB1PERIPH_BASE + 0X5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASE + 0X5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASE + 0X5C00)
#define I2S3ext_BASEADDR		(APB1PERIPH_BASE + 0X4000)

#define CAN1_BASEADDR			(APB1PERIPH_BASE + 0X6400)
#define CAN2_BASEADDR			(APB1PERIPH_BASE + 0X6800)

#define SPI2_BASEADDR			(APB1PERIPH_BASE + 0X3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASE + 0X3C00)

#define UART5_BASEADDR			(APB1PERIPH_BASE + 0X5000)
#define UART8_BASEADDR			(APB1PERIPH_BASE + 0X7C00)
#define UART7_BASEADDR			(APB1PERIPH_BASE + 0X7800)
#define UART4_BASEADDR			(APB1PERIPH_BASE + 0X4C00)
#define USART3_BASEADDR			(APB1PERIPH_BASE + 0X4800)
#define USART2_BASEADDR			(APB1PERIPH_BASE + 0X4400)

#define DAC_BASEADDR			(APB1PERIPH_BASE + 0X7400)
#define PWR_BASEADDR			(APB1PERIPH_BASE + 0X7000)


#define WWDG_BASEADDR			(APB1PERIPH_BASE + 0X2C00)
#define IWDG_BASEADDR			(APB1PERIPH_BASE + 0X3000)

#define TIM2_BASEADDR			(APB1PERIPH_BASE + 0X0000)
#define TIM3_BASEADDR			(APB1PERIPH_BASE + 0X0400)
#define TIM4_BASEADDR			(APB1PERIPH_BASE + 0X0800)
#define TIM5_BASEADDR			(APB1PERIPH_BASE + 0X0C00)
#define TIM6_BASEADDR			(APB1PERIPH_BASE + 0X1000)
#define TIM7_BASEADDR			(APB1PERIPH_BASE + 0X1400)
#define TIM12_BASEADDR			(APB1PERIPH_BASE + 0X1800)
#define TIM13_BASEADDR			(APB1PERIPH_BASE + 0X1C00)
#define TIM14_BASEADDR			(APB1PERIPH_BASE + 0X2000)

//Base address of Peripherals which are hanging on the APB2
#define SPI1_BASEADDR			(APB2PERIPH_BASE + 0X3000)
#define EXTI_BASEADDR 			(APB2PERIPH_BASE + 0X3C00)
#define USART1_BASEADDR 		(APB2PERIPH_BASE + 0X1000)
#define USART6_BASEADDR 		(APB2PERIPH_BASE + 0X1400)
#define SYSCFG_BASEADDR 		(APB2PERIPH_BASE + 0X3800)

/************************ Peripheral register definition structures *******************************/

/*
 * Note: Registers of a peripheral are specific to MCU
 * e.g: Number of registers of SPI peripheral od STM32F4x family of MCUs may be different  (more or less)
 * Compared to number of registers of SPI peripherals  of STM32Lx or STM32F0x families of MCU
 * Please check your Device RM
 */

typedef struct
{
	__vo uint32_t MODER;                                //GPIO port mode register
	__vo uint32_t OTYPER;								//GPIO port output type register
	__vo uint32_t OSPEEDR;								//GPIO port output speed register
	__vo uint32_t PUPDR;								//GPIO port pull-up/pull-down register
	__vo uint32_t IDR;									//GPIO port input data register
	__vo uint32_t ODR;									//GPIO port output data register
	__vo uint32_t BSRR;									//GPIO port bit set/reset register
	__vo uint32_t LCKR;									//GPIO port configuration lock register
	__vo uint32_t AFR[2];								//AFR[0] GPIO alternate function low register & AF[1] GPIO alternate function High register.

}GPIO_RegDef_t;

/*
 * Peripheral register definitions structure for RCC
 *
 */


typedef struct
{
	__vo uint32_t CR;									//0x00
	__vo uint32_t PLLCFGR;								//0x04
	__vo uint32_t CFGR;									//0x08
	__vo uint32_t CIR;									//0x0C
	__vo uint32_t AHB1RSTR;								//0x10
	__vo uint32_t AHB2RSTR;								//0x14
	__vo uint32_t AHB3RSTR;								//0x18
	uint32_t 	  RESERVED0;				//0X1C
	__vo uint32_t APB1RSTR;								//0x20
	__vo uint32_t APB2RSTR;								//0x24
	uint32_t      RESERVED1[2];              //0X28 & 0X2C
	__vo uint32_t AHB1ENR;								//0x30
	__vo uint32_t AHB2ENR;								//0x34
	__vo uint32_t AHB3ENR;								//0x38
	uint32_t RESERVED2;						//0x3C
	__vo uint32_t APB1ENR;								//0x40
	__vo uint32_t APB2ENR;								//0x44
	uint32_t RESERVED3[2];					//0x48 & 0x4C
	__vo uint32_t AHB1LPENR;							//0x50
	__vo uint32_t AHB2LPENR;							//0x54
	__vo uint32_t AHB3LPENR;							//0x58
	uint32_t RESERVED4;						//0x5C
	__vo uint32_t APB1LPENR;							//0x60
	__vo uint32_t APB2LPENR;							//0x64
	uint32_t RESERVED5[2];					//0x68 & 0x6C
	__vo uint32_t BDCR;									//0x70
	__vo uint32_t CSR;									//0x74
	uint32_t RESERVED6[2];					//0x78 & 0x7C
	__vo uint32_t SSCGR;								//0x80
	__vo uint32_t PLLI2SCFGR;							//0x84
	__vo uint32_t PLLSAICFGR;							//0x88
	__vo uint32_t DCKCFGR;								//0x8C



}RCC_RegDef_t;


/*
 * Peripheral register definitions structure for EXTI
 *
 */

typedef struct
{
	__vo uint32_t IMR; 		/*!< Give a short description, 		Address offset: 0x00 */
	__vo uint32_t EMR;		/*!< TODO, 							Address offset: 0x04 */
	__vo uint32_t RTSR; 	/*!< TODO, 							Address offset: 0x08 */
	__vo uint32_t FTSR;		/*!< TODO, 							Address offset: 0x0C */
	__vo uint32_t SWIER;	/*!< TODO, 							Address offset: 0x10 */
	__vo uint32_t PR;		/*!< TODO, 							Address offset: 0x14 */


}EXTI_RegDef_t;

/*
 * Peripheral register definitions structure for SYSCFG
 *
 */
typedef struct
{
	__vo uint32_t MEMRMP;		/*!< Give a short description, 		Address offset: 0x00 */
	__vo uint32_t PMC;			/*!< TODO, 							Address offset: 0x04 */
	__vo uint32_t EXTICR[4]; 	/*!< TODO, 							Address offset: 0x08 - 0x14 */
	uint32_t RESERVED1[2];		/*!< TODO, 							Reserved: 0x18 - 0x1c */
	__vo uint32_t CMPCR;		/*!< TODO, 							Address offset: 0x20 */
   uint32_t RESERVED2[2];		/*!< TODO, 							Reserved: 0x24 - 0x28 */
	__vo uint32_t CFGR;			/*!< TODO, 							Address offset: 0x2c */
}SYSCFG_RegDef_t;

/*
 * Peripheral definitions  (Peripheral base addresses typecasted to xxx_RegDef_t)
 *
 *
 */

#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE					((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF					((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG					((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH					((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI					((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define RCC 					((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI   					((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG   				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()			(RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()			(RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |=(1<<7))
#define GPIOI_PCLK_EN()			(RCC->AHB1ENR |=(1<<8))

/*
 * Clock Enable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_EN()			(RCC->APB1ENR |=(1<<21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR |=(1<<22))
#define I2C3_PCLK_EN()			(RCC->APB1ENR |=(1<<23))

/*
 * Clock Enable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_EN()			(RCC->APB2ENR |=(1<<12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |=(1<<14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR |=(1<<15))

/*
 * Clock Enable Macros for USARTx Peripherals
 */
#define USART1_PCLK_EN()			(RCC->APB2ENR |=(1<<04))
#define USART2_PCLK_EN()			(RCC->APB1ENR |=(1<<17))
#define USART3_PCLK_EN()			(RCC->APB1ENR |=(1<<18))
#define USART6_PCLK_EN()			(RCC->APB2ENR |=(1<<05))
/*
 * Clock Enable Macros for SYSCFGx Peripherals
 */
#define SYSCFG_PCLK_EN()			(RCC->APB2ENR |=(1<<14))

/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()			(RCC->AHB1ENR &= ~(1<<8))

/*
 * Clock Disable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<23))

/*
 * Clock Disable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<15))

/*
 * Clock Disable Macros for USARTx Peripherals
 */
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1<<04))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DI()			(RCC->APB1ENR &= ~(1<<18))
#define USART6_PCLK_DI()			(RCC->APB2ENR &= ~(1<<05))
/*
 * Clock Disable Macros for SYSCFGx Peripherals
 */
#define SYSCFG_PCLK_DI()			(RCC->APB2ENR &= ~(1<<14))


/*
 * Macros to RESET GPIOx Peripherals
 */
#define GPIOA_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<0)); (RCC->AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<1)); (RCC->AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<2)); (RCC->AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<3)); (RCC->AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<4)); (RCC->AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<5)); (RCC->AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<6)); (RCC->AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<7)); (RCC->AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()			do { (RCC->AHB1RSTR |=(1<<8)); (RCC->AHB1RSTR &= ~(1<<8)); }while(0)

#define GPIOA_BASEADDR_TO_CODE(x) ( (x==GPIOA) ? 0 : \
									(x==GPIOB) ? 1 : \
									(x==GPIOB) ? 2 : \
								    (x==GPIOB) ? 3 : \
								    (x==GPIOB) ? 4 : \
								    (x==GPIOB) ? 5 : \
								    (x==GPIOB) ? 6 : \
								    (x==GPIOB) ? 7 : 0 )

/*
 * IRQ(Interrupt Request) Number of stm32f40x MCU
 * NOTE: Update these macros with valid  values according to mcu
 * TODO: You may complete this list for other peripherals
 */
#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40
#define IRQ_NO_TIM2			28
#define IRQ_NO_TIM3			29
#define IRQ_NO_TIM4			30
#define IRQ_NO_I2C1_EV		31
#define IRQ_NO_I2C1_ER		32
#define IRQ_NO_SPI1			35
#define IRQ_NO_SPI2			36
#define IRQ_NO_USART1		37
#define IRQ_NO_USART2		38
#define IRQ_NO_USART3		39
#define IRQ_NO_SPI3			51
#define IRQ_NO_UART4		52
#define IRQ_NO_UART5		53
#define IRQ_NO_USART6		71


/*
 * Macros for all the priority levels
 */
#define NVIC_IRQ_PRI0    0
#define NVIC_IRQ_PRI1    1
#define NVIC_IRQ_PRI2    2
#define NVIC_IRQ_PRI3    3
#define NVIC_IRQ_PRI4    4
#define NVIC_IRQ_PRI5    5
#define NVIC_IRQ_PRI6    6
#define NVIC_IRQ_PRI7    7
#define NVIC_IRQ_PRI8    8
#define NVIC_IRQ_PRI9    9
#define NVIC_IRQ_PRI10   10
#define NVIC_IRQ_PRI11   11
#define NVIC_IRQ_PRI12   12
#define NVIC_IRQ_PRI13   13
#define NVIC_IRQ_PRI14   14
#define NVIC_IRQ_PRI15   15

/*
 * Some Generic Macros
 */

#define ENABLE 						1
#define DISABLE						0
#define SET							ENABLE
#define RESET						DISABLE
#define GPIO_PIN_SET				SET
#define GPIO_PIN_RESET				RESET

#include "stm32f407xx_gpio_driver.h"
#endif /* INC_STM32F407XX_H_ */
