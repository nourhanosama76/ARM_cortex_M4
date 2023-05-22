/*
 * NVIC_private.h
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

typedef struct
{
	u32 ISER[8]       ;
	u32 Reserved1[24] ;
	u32 ICER[32]      ;
	u32 Reserved2[24] ;
	u32 ISPR[32]      ;
	u32 ICPR[32]      ;
	u32 IABR[64]      ;
	u8  IPR[240]      ;                  //instead of 8 registers, each has 4bytes
}NVIC_t ;



#define NVIC            ((volatile NVIC_t *)(0xE000E100))

//register to configure how to divide SW priority between group and sub for the system
#define SCB_AIRCR       (*(volatile u32*)(0xE000ED0C))

#define VECT_KEY        (0x0F5A0000)     //

#define GROUP4_SUB0     (0)              //supports 16 groups(nesting level up to 16)
#define GROUP3_SUB1     (4)              //supports 8 groups and 2 sub
#define GROUP2_SUB2     (5)              //supports 4 groups and 4 sub
#define GROUP1_SUB3     (6)              //supports 2 groups and 8 sub
#define GROUP0_SUB4     (7)              //supports 0 groups and 16 sub(no nesting)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
