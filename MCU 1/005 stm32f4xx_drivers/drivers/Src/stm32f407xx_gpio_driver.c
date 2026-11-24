/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Jul 14, 2026
 *      Author: CITI
 */


#include <stm32f407xx_gpio_driver.h>


/*
 * Peripheral Clock Setup
 */

/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIOx ==  GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}

	}else
	{
		//To Do from ref manual
		if (pGPIOx ==  GPIOA)
				{
					GPIOA_PCLK_DI();
				}else if (pGPIOx == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if (pGPIOx == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if (pGPIOx == GPIOD)
				{
					GPIOD_PCLK_DI();
				}else if (pGPIOx == GPIOE)
				{
					GPIOE_PCLK_DI();
				}else if (pGPIOx == GPIOF)
				{
					GPIOF_PCLK_DI();
				}else if (pGPIOx == GPIOG)
				{
					GPIOG_PCLK_DI();
				}else if (pGPIOx == GPIOH)
				{
					GPIOH_PCLK_DI();
				}else if (pGPIOx == GPIOI)
				{
					GPIOI_PCLK_DI();
				}
	}

}

/*
 * Init and DeInit
 */

/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0;    //temp.register
	//1, Configure the Mode of the GPIO Pin
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//Non Interrupt Mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2 *pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber ));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //Clearing
		pGPIOHandle->pGPIOx->MODER |= temp; //setting



	}else
	{
		//This part will comes later (Interrupt Mode)

		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//1. Configure the FTSR

			EXTI->FTSR |=  (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
			//Clearing the Corresponding RTST bit
			EXTI->RTSR &=  ~ (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);

		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1. Configure the RTSR
			EXTI->RTSR |=  (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
			//Clearing the Corresponding FTST bit
			EXTI->FTSR &=  ~ (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);

		}else if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
		{
			//1. Configure both the FTSR and RTSR
			EXTI->RTSR |=  (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);

			EXTI->FTSR |=  (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
		}

		//2. Configure the GPIO port selection in SYSCFG_EXTICR
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIOA_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] = portcode << (temp2*4);

		//3. Enable the EXTI interrupt delivery using IMR
		EXTI->IMR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
	}
	temp =0;
	//2. Configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;

	//3. Configure the PUPD settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl  << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	//4. Configure the OPTYPE
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 <<pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //Clearing
	pGPIOHandle->pGPIOx->OTYPER |= temp;



	//5. Configure the ALT Functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		//Config the Alt function registers.
		uint32_t temp1,temp2;

		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber /8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

		if (pGPIOx ==  GPIOA)
		{
			GPIOA_REG_RESET();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_REG_RESET();
		}else if (pGPIOx == GPIOG)
		{
			GPIOG_REG_RESET();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_REG_RESET();
		}else if (pGPIOx == GPIOI)
		{
			GPIOI_REG_RESET();
		}
}

/*
 * Data read and write
 */

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t) ((pGPIOx->IDR >>  PinNumber) & 0x00000001);
	return value;
}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t) pGPIOx->IDR;
	return value;

}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOuputPin
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */

void GPIO_WriteToOuputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//Write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx ->ODR|= (1 << PinNumber);

	}
	else
	{
		pGPIOx ->ODR&= ~(1 << PinNumber);
	}
}

/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	 pGPIOx->ODR = pGPIOx-> ODR ^ (1<<PinNumber);

}

/*
 * IRQ configuration and ISR Handling
 */

/*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(IRQNumber <=31)
		{
			//Program ISER0 Register
			*NVIC_ISER0 |= (1 <<IRQNumber);

		}else if (IRQNumber > 31 && IRQNumber <64) // 32 to 63
		{
			//Program ISER1 Register
			*NVIC_ISER1 |= (1 <<IRQNumber % 32);
		}
		else if (IRQNumber > 64 && IRQNumber < 96) //64 to 95
		{
			//Program ISER2 Register
			*NVIC_ISER1 |= (1 <<IRQNumber % 64);
		}
	}else
	{
		if(IRQNumber <=31)
			{
				//Program ICER0 Register
			*NVIC_ICER0 |= (1 <<IRQNumber);

			}else if (IRQNumber > 31 && IRQNumber <64) // 32 to 63
			{
				//Program ICER1 Register
			*NVIC_ICER1 |= (1 <<IRQNumber % 32);
			}
			else if (IRQNumber > 64 && IRQNumber < 96) //64 to 95
			{
				//Program ICER2 Register
			*NVIC_ISER1 |= (1 <<IRQNumber % 64);
			}
	}

}


/*********************************************************************
 * @fn      		  - GPIO_IRQPriorityConfig
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
 //1. First lets find out the IPR register
	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_section = IRQNumber%4;


	uint8_t shift_amount = (8*iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + (iprx)) |=  (IRQPriority << shift_amount);

}


/*********************************************************************
 * @fn      		  - GPIO_IRQHandling
 *
 * @brief             - This function Initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
 // clearing the exti pr register corresponding to the pin number
	if(EXTI->PR & (1<< PinNumber))
	{
		 	//clear
		EXTI->PR |= (1<<PinNumber);
	}
}



