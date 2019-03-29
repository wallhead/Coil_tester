/******************************************************************************
**************************Hardware interface layer*****************************
* | file      	:	DEV_Config.h
* |	version		:	V1.0
* | date		:	2017-08-14
* | function	:	
	Provide the hardware underlying interface	
******************************************************************************/
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

//#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_gpio.h"
//#include "main.h"
#include "stm32f4xx.h"
#include "stdint.h"
//#define USE_SPI_4W 1
//#define USE_IIC 0

#define IIC_CMD        0X00
#define IIC_RAM        0X40

//OLED GPIO
#define OLED_CS_0		GPIOB->BSRR = GPIO_BSRR_BR_12
#define OLED_CS_1		GPIOB->BSRR = GPIO_BSRR_BS_12

#define OLED_DC_0		GPIOB->BSRR = GPIO_BSRR_BR_14
#define OLED_DC_1		GPIOB->BSRR = GPIO_BSRR_BS_14

#define OLED_RST_0		GPIOC->BSRR = GPIO_BSRR_BR_6
#define OLED_RST_1		GPIOC->BSRR = GPIO_BSRR_BS_6

//SPI GPIO
//#define SPI1_SCK_0		HAL_GPIO_WritePin(SPI1_SCK_GPIO_Port, SPI1_SCK_Pin, GPIO_PIN_RESET)
//#define SPI1_SCK_1		HAL_GPIO_WritePin(SPI1_SCK_GPIO_Port, SPI1_SCK_Pin, GPIO_PIN_SET)

//#define SPI1_MOSI_0		HAL_GPIO_WritePin(SPI1_MOSI_GPIO_Port, SPI1_MOSI_Pin, GPIO_PIN_RESET)
//#define SPI1_MOSI_1		HAL_GPIO_WritePin(SPI1_MOSI_GPIO_Port, SPI1_MOSI_Pin, GPIO_PIN_SET)
/*------------------------------------------------------------------------------------------------------*/

uint8_t System_Init(void);
void    System_Exit(void);

uint8_t SPI4W_Write_Byte(uint8_t value);
void I2C_Write_Byte(uint8_t value, uint8_t Cmd);

void Driver_Delay_ms(uint32_t xms);
void Driver_Delay_us(uint32_t xus);

#endif
