/*
 * EXTI_program.c
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_cfg.h"


void EXTI_voidEnableINT(u8 Copy_u8INTID , void(*Copy_PtrToFun)(void))
{
	SET_BIT(EXTI->IMR , Copy_u8INTID) ;
}

void EXTI_voidDisableINT(u8 Copy_u8INTID)
{
	CLR_BIT(EXTI->IMR , Copy_u8INTID) ;
}

void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8INTID)
{
	switch(Copy_u8SenseSignal)
	{
	case RISING_EDGE :
		CLR_BIT(EXTI->FTSR , Copy_u8INTID);
		SET_BIT(EXTI->RTSR , Copy_u8INTID);
		break ;

	case FALLING_EDGE :
		CLR_BIT(EXTI->RTSR , Copy_u8INTID);
		SET_BIT(EXTI->FTSR , Copy_u8INTID);
		break ;

	case ON_CHANGE :
		SET_BIT(EXTI->RTSR , Copy_u8INTID);
		SET_BIT(EXTI->FTSR , Copy_u8INTID);
		break ;
	}
}


void EXTI_voidSetLinePort(u8 Copy_u8INTID , u8 Copy_u8PortID)
{

}
