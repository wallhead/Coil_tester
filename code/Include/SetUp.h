
#ifndef INCLUDE_SETUP_H_
#define INCLUDE_SETUP_H_

#include "stm32f4xx.h"
#include "stm32f4xx_ll_spi.h"
/*---------------------------------------------------------------------------*/

void RCC_Init (void);
void MCO_out (void);
void ADC1_Init(void);
void Display_spi2_init(void);
void PORTB_Init(void);
void TIM2_PWM_Init(void);
void TIM3_Master_Init(void);
void TIM4_Slave_Init(void);
void TIM5_Slave_Init(void);
void ADC_PipelineBus_Init(void);
/*---------------------------------------------------------------------------*/
#endif /* INCLUDE_SETUP_H_ */
