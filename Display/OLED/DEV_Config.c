/******************************************************************************
**************************Hardware interface layer*****************************
* | file      	:	DEV_Config.c
* |	version		:	V1.0
* | date		:	2017-08-14
* | function	:	
	Provide the hardware underlying interface	
******************************************************************************/
#include "DEV_Config.h"
//#include "stm32f1xx_hal_i2c.h"
//#include "i2c.h"

#include "stm32f4xx_ll_spi.h"
//#include "spi.h"

//#include "usart.h"
#include <stdio.h>		//printf()
#include <string.h>
#include <stdlib.h>

/********************************************************************************
function:	System Init
note:
	Initialize the communication method
********************************************************************************/
uint8_t System_Init(void)
{
#if USE_SPI_4W
    //printf("USE 4wire spi\r\n");
#elif USE_IIC
    printf("USE i2c\r\n");
	//DC = 1 => addrdess = 0X3D
	//DC = 0 => addrdess = 0X3C
	OLED_DC_1;
#endif
    return 0;
}

void System_Exit(void)
{

}
/********************************************************************************
function:	Hardware interface
note:
	SPI4W_Write_Byte(value) : 
		HAL library hardware SPI
		Register hardware SPI
		Gpio analog SPI
	I2C_Write_Byte(value, cmd):
		HAL library hardware I2C
********************************************************************************/
uint8_t SPI4W_Write_Byte(uint8_t value)
{

    while(!(SPI2->SR & SPI_SR_TXE));

    *((volatile uint8_t *)(&SPI2->DR)) = value;

    while(SPI2->SR & LL_SPI_IsActiveFlag_BSY(SPI2)) ; //Wait for not busy

//    while((SPI2->SR & (1 << 0)) == 0) ; 			  // Wait for the receiving area to be empty

    return *((volatile uint8_t *)(&SPI2->DR));

}



/********************************************************************************
function:	Delay function
note:
	Driver_Delay_ms(xms) : Delay x ms
	Driver_Delay_us(xus) : Delay x us
********************************************************************************/
void Driver_Delay_ms(uint32_t xms)
{
    int j;
    for(j=xms; j > 0; j--);
}

void Driver_Delay_us(uint32_t xus)
{
    int j;
    for(j=xus; j > 0; j--);
}
