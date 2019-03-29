#include "stm32f4xx.h"
#include  "setup.h"
#include "defines.h"
/*---------------------------------------------------------------------------*/
void RCC_Init(void);
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

void ADC_PipelineBus_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN ;
	GPIOA->MODER &= ~(GPIO_MODER_MODER1 | GPIO_MODER_MODER2 | GPIO_MODER_MODER3 | GPIO_MODER_MODER4 | GPIO_MODER_MODER5 | GPIO_MODER_MODER6 | GPIO_MODER_MODER7);
	GPIOB->MODER &= ~(GPIO_MODER_MODER0 | GPIO_MODER_MODER1 | GPIO_MODER_MODER2);
	GPIOC->MODER &= ~(GPIO_MODER_MODER4 | GPIO_MODER_MODER5);

	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_1 | GPIO_OTYPER_OT_2 | GPIO_OTYPER_OT_3 | GPIO_OTYPER_OT_4 | GPIO_OTYPER_OT_5 | GPIO_OTYPER_OT_6 | GPIO_OTYPER_OT_7);
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_0 | GPIO_OTYPER_OT_1 | GPIO_OTYPER_OT_2);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_4 | GPIO_OTYPER_OT_5);

	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR3 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0 | GPIO_OSPEEDER_OSPEEDR1 | GPIO_OSPEEDER_OSPEEDR2;
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5 ;

	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR1_0 | GPIO_PUPDR_PUPDR2_0 | GPIO_PUPDR_PUPDR3_0 | GPIO_PUPDR_PUPDR4_0 | GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR7_0;
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR0_0 | GPIO_PUPDR_PUPDR1_0 | GPIO_PUPDR_PUPDR2_0;
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR4_0 | GPIO_PUPDR_PUPDR5_0;
}
/*---------------------------------------------------------------------------*/

void TIM2_PWM_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ;
	GPIOB->MODER |= GPIO_MODER_MODER10_1;		// AF1
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_10;		// push-pull
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	// 50 Mhz
	GPIOB->AFR[1] |= GPIO_AFRH10_0;				// AF1 TIM2 Chanel 3 PWM

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 0;								// prescaler
	TIM2->ARR = 11;
	TIM2->CCR3 = 6;
	TIM2->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3P;
	TIM2->BDTR |= TIM_BDTR_MOE;
	TIM2->CCMR2 = TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;
	TIM2->CR2 |= TIM_CR2_MMS_0; 				// master mode enable
	TIM2->SMCR |= TIM_SMCR_MSM;
	TIM2->CR1 &= ~TIM_CR1_DIR;					//
	TIM2->CR1 &= ~TIM_CR1_CMS;

}
/*---------------------------------------------------------------------------*/

void TIM3_Master_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN ;
	GPIOC->MODER |= GPIO_MODER_MODER8_1;		// AF1
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT_8;			// push-pull
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;	// 50 Mhz
	GPIOC->AFR[1] |= GPIO_AFRH8_1;				// AF2 TIM 3 Chanel PWM

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 0;								// prescaler
	TIM3->ARR = 11;
	TIM3->CCR3 = 6;
	TIM3->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3P;
	TIM3->BDTR |= TIM_BDTR_MOE;
	TIM3->CCMR2 = TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;
	TIM3->CR2 |= TIM_CR2_MMS_0; 				// master mode enable
	TIM3->SMCR |= TIM_SMCR_MSM;
	TIM3->CR1 &= ~TIM_CR1_DIR;					//
	TIM3->CR1 &= ~TIM_CR1_CMS;

	}

/*---------------------------------------------------------------------------*/

void TIM4_Slave_Init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ;
	GPIOB->MODER |= GPIO_MODER_MODER8_1;		// AF1
	GPIOB->OTYPER &= ~GPIO_OTYPER_OT_8;			// push-pull
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;	// 50 Mhz
	GPIOB->AFR[1] |= GPIO_AFRH8_1;				// AF2 TIM 4 Chanel PWM

	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 0;								// prescaler
	TIM4->ARR = 11;
	TIM4->CCR3 = 6;
	TIM4->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3P;
	TIM4->BDTR |= TIM_BDTR_MOE;
	TIM4->CCMR2 = TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;
	TIM4->SMCR |= TIM_SMCR_TS_1;					// ITR2
	TIM4->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_2 ;					// slave mode external clock
	TIM4->CNT = 7;
	TIM4->CR1 &= ~TIM_CR1_DIR;					//
	TIM4->CR1 &= ~TIM_CR1_CMS;

}
/*---------------------------------------------------------------------------*/

void TIM5_Slave_Init(void)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
		TIM5->PSC = 0;													// prescaler
		TIM5->ARR = 11;
		TIM5->CCR3 = 6;
		TIM5->CCER |= TIM_CCER_CC3P;
		TIM5->CCMR2 = TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;
		TIM5->SMCR &= ~TIM_SMCR_TS;										// ITR2
		TIM5->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_2 ;					// slave gated mode
		TIM5->CNT = 6;
		TIM5->DIER |= TIM_DIER_CC3IE;
		TIM5->CR1 &= ~TIM_CR1_DIR;										//
		TIM5->CR1 &= ~TIM_CR1_CMS;
	}

/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
void RCC_Init (void)
	{
	//RCC->CR &= (uint32_t)0xFEF6FFFF;			// Reset HSEON, CSSON and PLLON bits
    RCC->CR |= ((uint32_t)RCC_CR_HSEON); 		// Enable HSE
    while (!(RCC->CR & RCC_CR_HSERDY));			// Ready start HSE

    FLASH->ACR = FLASH_ACR_LATENCY_3WS;			// Flash latency 3 ws

    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;			// Reset PLLCFGR_PLLN
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;			// Reset PLLCFGR_PLLM
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;		// HSE source of PLL
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_3;			// HSE/8
    RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_6
    			  |  RCC_PLLCFGR_PLLN_7  );		// (HSE/8)*192
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP; 			// ((HSE/8)*192)/2 = 96 MHz

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;			// AHB not divided
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;			// APB1/2
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;			// APB2/1

    RCC->CR |= RCC_CR_PLLON;                      			// enable PLL
    while((RCC->CR & RCC_CR_PLLRDY) == 0) {}      			// wait till PLL is ready

    RCC->CFGR &= ~RCC_CFGR_SW;                   			// clear SW bits
    RCC->CFGR |= RCC_CFGR_SW_PLL;                 			// select source SYSCLK = PLL
    while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {}  // wait till PLL is used



  }
/*---------------------------------------------------------------------------*/

void MCO_out (void)
  {

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;                    // enable clock for port C

    GPIOC->MODER |= GPIO_MODER_MODER9_1;					// setting out AF PC9
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT_9;						// PC9 PushPull
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR9;						// PC9 no pull/push
    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;				// PC9 High Speed
    GPIOC->AFR[0] = GPIO_AFRL_RESET;
    GPIOC->AFR[1] = GPIO_AFRH_RESET;
    RCC->CFGR  &= ~RCC_CFGR_MCO2;							// select source clock SYSCLK
    RCC->CFGR |= RCC_CFGR_MCO2PRE_2;						// MCO = SYSCLK/2

  }

/*---------------------------------------------------------------------------*/

void ADC1_Init(void)
{

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;					// enable clock for port A
	GPIOA->MODER |= GPIO_MODER_MODER0;						// analog mode PA0
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;				// PA0 High Speed

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN ;					// enable clock for ADC1
    ADC1->CR1 &= ~ADC_CR1_OVRIE;							// disable overrun interrupt
    ADC1->CR1 |= ADC_CR1_RES;								// 8 bit res mode
    ADC1->SMPR2 &= ~ADC_SMPR2_SMP0;							// sampling time 3 cycles
    ADC1->SQR1 &= ~ADC_SQR1_L ;								// 1 conversion
    ADC1->SQR2 = 0;
	ADC1->SQR3 &= ~ADC_SQR3_SQ1_0;							// ADC_IN_0
	ADC->CCR |= ADC_CCR_ADCPRE_1 ;							// PCLK2/4
	ADC1->CR2 |= ADC_CR2_ADON;								// power on ADC1

	ADC1->CR2 |= ADC_CR2_CONT | ADC_CR2_SWSTART ;			// start Continuous mode
   }
/*---------------------------------------------------------------------------*/

void Display_spi2_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN ;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN ;

	GPIOB->MODER |= GPIO_MODER_MODER12_0 | GPIO_MODER_MODER14_0;
	GPIOB->MODER |= GPIO_MODER_MODER13_1 | GPIO_MODER_MODER15_1;
	GPIOC->MODER |= GPIO_MODER_MODER6_0;
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_12 | GPIO_OTYPER_OT_14);
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_15 | GPIO_OTYPER_OT_13);
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT_6;
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13 | GPIO_OSPEEDER_OSPEEDR15 | GPIO_OSPEEDER_OSPEEDR12 | GPIO_OSPEEDER_OSPEEDR14;
	GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;
	GPIOB->AFR[1] |= GPIO_AFRH13_0 | GPIO_AFRH13_2 | GPIO_AFRH15_0 | GPIO_AFRH15_2;

	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;

	LL_SPI_SetMode(SPI2,LL_SPI_MODE_MASTER);
	LL_SPI_SetClockPhase(SPI2,LL_SPI_PHASE_1EDGE);
	LL_SPI_SetClockPolarity(SPI2,LL_SPI_POLARITY_LOW);
	LL_SPI_SetBaudRatePrescaler(SPI2,LL_SPI_BAUDRATEPRESCALER_DIV2);
	LL_SPI_SetTransferBitOrder(SPI2,LL_SPI_MSB_FIRST);
	LL_SPI_SetTransferDirection(SPI2,LL_SPI_HALF_DUPLEX_TX);
	LL_SPI_SetDataWidth(SPI2,LL_SPI_DATAWIDTH_8BIT);
	LL_SPI_DisableCRC(SPI2);
	LL_SPI_SetNSSMode(SPI2,LL_SPI_NSS_SOFT);
	LL_SPI_Enable(SPI2);
	}

/*---------------------------------------------------------------------------*/

