/*
 * EXTI_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*16 macro for EXTI lines*/


/*3 macros for sense signals*/
#define FALLING_EDGE         1
#define RISING_EDGE          2
#define ON_CHANGE            3


void EXTI_voidEnableINT(u8 Copy_u8INTID , void(*Copy_PtrToFun)(void));

void EXTI_voidDisableINT(u8 Copy_u8INTID);

void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8INTID);

void EXTI_voidSetLinePort(u8 Copy_u8INTID , u8 Copy_u8PortID);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
