/*
 * NVIC_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


/*this function is to initialize NVIC, set priority configurations*/
void NVIC_voidInit(void);    //msh ht3dl haga fe run time y3ni hkhleha prebuild

void NVIC_voidEnableINT(u8 Copy_u8INTID);

void NVIC_voidDisableINT(u8 Copy_u8INTID);

void NVIC_voidSetPendingFlag(u8 Copy_u8INTID);

void NVIC_voidClearPendingFlag(u8 Copy_u8INTID);

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8INTID);

void NVIC_voidSetSWPriority(u8 Copy_u8SWPrioity , u8 Copy_u8INTID);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
