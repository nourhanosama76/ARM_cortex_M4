/*
 * NVIC_program.c
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_cfg.h"


void NVIC_voidInit(void)
{
	/*variable for the value of AIRCR register*/
	u32 Local_u32RegisterValue ;

	/*set configuration of system priorities*/
	Local_u32RegisterValue = VECT_KEY |(PRIORITY_CONFIG << 8) ;

	/*assign the value to AIRCR*/
	SCB_AIRCR = Local_u32RegisterValue ;
}


void NVIC_voidEnableINT(u8 Copy_u8INTID)
{
	NVIC->ISER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32) ;
}

void NVIC_voidDisableINT(u8 Copy_u8INTID)
{
	NVIC->ICER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32) ;
}

void NVIC_voidSetPendingFlag(u8 Copy_u8INTID)
{
	NVIC->ISPR[Copy_u8INTID] = 1 << (Copy_u8INTID % 32) ;
}

void NVIC_voidClearPendingFlag(u8 Copy_u8INTID)
{
	NVIC->ICPR[Copy_u8INTID] = 1 << (Copy_u8INTID % 32) ;
}

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8INTID)
{
	u8 Local_u8ActiveFlag ;
	Local_u8ActiveFlag = GET_BIT(NVIC -> IABR[Copy_u8INTID / 32] , (Copy_u8INTID % 32)) ;
    return Local_u8ActiveFlag ;
}


void NVIC_voidSetSWPriority(u8 Copy_u8SWPrioity , u8 Copy_u8INTID)
{
	/*setting both group and sub-priorities into the high 4bits*/
	NVIC->IPR[Copy_u8INTID] = Copy_u8SWPrioity << 4 ;

	//TODO -> enhance the function !!!!
}
