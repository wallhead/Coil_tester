/*
 * defines.h
 *
 *  Created on: 29 мар. 2019 г.
 *      Author: koroteev_d
 */

#ifndef INCLUDE_DEFINES_H_
#define INCLUDE_DEFINES_H_

//--------------------------------Delay--------------------------------------//

#define CPU_CLK         96000000UL
#define xms             CPU_CLK/1000-1
#define xus             CPU_CLK/1000000UL-1

//---------------------------GPIO_Defines--------------------------------------//

/******************  Bits definition for GPIO_AFR[0] register  ****************/

#define GPIO_AFRL_RESET	((uint32_t)0x00000000)

#define GPIO_AFRL0	    ((uint32_t)0x0000000F)
#define GPIO_AFRL0_0	((uint32_t)0x00000001)
#define GPIO_AFRL0_1	((uint32_t)0x00000002)
#define GPIO_AFRL0_2	((uint32_t)0x00000004)
#define GPIO_AFRL0_3	((uint32_t)0x00000008)

#define GPIO_AFRL1		((uint32_t)0x000000F0)
#define GPIO_AFRL1_0	((uint32_t)0x00000010)
#define GPIO_AFRL1_1	((uint32_t)0x00000020)
#define GPIO_AFRL1_2	((uint32_t)0x00000040)
#define GPIO_AFRL1_3	((uint32_t)0x00000080)

#define GPIO_AFRL2		((uint32_t)0x00000F00)
#define GPIO_AFRL2_0	((uint32_t)0x00000100)
#define GPIO_AFRL2_1	((uint32_t)0x00000200)
#define GPIO_AFRL2_2	((uint32_t)0x00000400)
#define GPIO_AFRL2_3	((uint32_t)0x00000800)

#define GPIO_AFRL3		((uint32_t)0x0000F000)
#define GPIO_AFRL3_0	((uint32_t)0x00001000)
#define GPIO_AFRL3_1	((uint32_t)0x00002000)
#define GPIO_AFRL3_2	((uint32_t)0x00004000)
#define GPIO_AFRL3_3	((uint32_t)0x00008000)

#define GPIO_AFRL4		((uint32_t)0x000F0000)
#define GPIO_AFRL4_0	((uint32_t)0x00010000)
#define GPIO_AFRL4_1	((uint32_t)0x00020000)
#define GPIO_AFRL4_2	((uint32_t)0x00040000)
#define GPIO_AFRL4_3	((uint32_t)0x00080000)

#define GPIO_AFRL5		((uint32_t)0x00F00000)
#define GPIO_AFRL5_0	((uint32_t)0x00100000)
#define GPIO_AFRL5_1	((uint32_t)0x00200000)
#define GPIO_AFRL5_2	((uint32_t)0x00400000)
#define GPIO_AFRL5_3	((uint32_t)0x00800000)

#define GPIO_AFRL6		((uint32_t)0x0F000000)
#define GPIO_AFRL6_0	((uint32_t)0x01000000)
#define GPIO_AFRL6_1	((uint32_t)0x02000000)
#define GPIO_AFRL6_2	((uint32_t)0x04000000)
#define GPIO_AFRL6_3	((uint32_t)0x08000000)

#define GPIO_AFRL7		((uint32_t)0xF0000000)
#define GPIO_AFRL7_0	((uint32_t)0x10000000)
#define GPIO_AFRL7_1	((uint32_t)0x20000000)
#define GPIO_AFRL7_2	((uint32_t)0x40000000)
#define GPIO_AFRL7_3	((uint32_t)0x80000000)

/******************  Bits definition for GPIO_AFR[1] register  ****************/

#define GPIO_AFRH_RESET	((uint32_t)0x00000000)

#define GPIO_AFRH8		((uint32_t)0x0000000F)
#define GPIO_AFRH8_0	((uint32_t)0x00000001)
#define GPIO_AFRH8_1	((uint32_t)0x00000002)
#define GPIO_AFRH8_2	((uint32_t)0x00000004)
#define GPIO_AFRH8_3	((uint32_t)0x00000008)

#define GPIO_AFRH9		((uint32_t)0x000000F0)
#define GPIO_AFRH9_0	((uint32_t)0x00000010)
#define GPIO_AFRH9_1	((uint32_t)0x00000020)
#define GPIO_AFRH9_2	((uint32_t)0x00000040)
#define GPIO_AFRH9_3	((uint32_t)0x00000080)

#define GPIO_AFRH10		((uint32_t)0x00000F00)
#define GPIO_AFRH10_0	((uint32_t)0x00000100)
#define GPIO_AFRH10_1	((uint32_t)0x00000200)
#define GPIO_AFRH10_2	((uint32_t)0x00000400)
#define GPIO_AFRH10_3	((uint32_t)0x00000800)

#define GPIO_AFRH11		((uint32_t)0x0000F000)
#define GPIO_AFRH11_0	((uint32_t)0x00001000)
#define GPIO_AFRH11_1	((uint32_t)0x00002000)
#define GPIO_AFRH11_2	((uint32_t)0x00004000)
#define GPIO_AFRH11_3	((uint32_t)0x00008000)

#define GPIO_AFRH12		((uint32_t)0x000F0000)
#define GPIO_AFRH12_0	((uint32_t)0x00010000)
#define GPIO_AFRH12_1	((uint32_t)0x00020000)
#define GPIO_AFRH12_2	((uint32_t)0x00040000)
#define GPIO_AFRH12_3	((uint32_t)0x00080000)

#define GPIO_AFRH13		((uint32_t)0x00F00000)
#define GPIO_AFRH13_0	((uint32_t)0x00100000)
#define GPIO_AFRH13_1	((uint32_t)0x00200000)
#define GPIO_AFRH13_2	((uint32_t)0x00400000)
#define GPIO_AFRH13_3	((uint32_t)0x00800000)

#define GPIO_AFRH14		((uint32_t)0x0F000000)
#define GPIO_AFRH14_0	((uint32_t)0x01000000)
#define GPIO_AFRH14_1	((uint32_t)0x02000000)
#define GPIO_AFRH14_2	((uint32_t)0x04000000)
#define GPIO_AFRH14_3	((uint32_t)0x08000000)

#define GPIO_AFRH15		((uint32_t)0xF0000000)
#define GPIO_AFRH15_0	((uint32_t)0x10000000)
#define GPIO_AFRH15_1	((uint32_t)0x20000000)
#define GPIO_AFRH15_2	((uint32_t)0x40000000)
#define GPIO_AFRH15_3	((uint32_t)0x80000000)



#endif /* INCLUDE_DEFINES_H_ */
