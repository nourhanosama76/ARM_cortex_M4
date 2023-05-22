/*
 * EXTI_private.h
 *
 *  Created on: May 22, 2023
 *      Author: Nourhan
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_


typedef struct
{
	u32 IMR   ;        //interrupt mask register
	u32 EMR   ;        //event mask register
	u32 RTSR  ;        //rising edge trigger selection register
	u32 FTSR  ;        //falling edge trigger selection register
	u32 SWIER ;        //SW interrupt event register
	u32 PR    ;        //pending register
}EXTI_t;



#define EXTI ((volatile EXTI_t*)(0x40013C00))


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
