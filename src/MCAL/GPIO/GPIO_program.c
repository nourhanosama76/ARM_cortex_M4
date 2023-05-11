/*
 * GPIO_program.c
 *
 *  Created on: May 11, 2023
 *      Author: Nourhan
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_LIB.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_cfg.h"

void GPIO_voidInitOutputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinType , u8 Copy_u8PinSpeed)
{

	switch (Copy_u8PortID)
	{
	case GPIO_PORTA :

		/*set the direction of pi to be output*/
		/*bit masking*/
		GPIOA->MODER &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOA->MODER |= (0b01<<(Copy_u8PinID*2))  ;


		/*set speed of the input pin*/
		/*bit masking*/
		GPIOA->OSPEEDR &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOA->OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2))  ;

		/*set type of output pin*/
		WRT_BIT(GPIOA->OTYPER , Copy_u8PinID , Copy_u8PinType) ;

		break ;

	case GPIO_PORTB :
		/*set the direction of pi to be output*/
		/*bit masking*/
		GPIOB->MODER &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOB->MODER |= (0b01<<(Copy_u8PinID*2))  ;


		/*set speed of the input pin*/
		/*bit masking*/
		GPIOB->OSPEEDR &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOB->OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2))  ;

		/*set type of output pin*/
		WRT_BIT(GPIOB->OTYPER , Copy_u8PinID , Copy_u8PinType) ;
		break ;

	case GPIO_PORTC :
		/*set the direction of pi to be output*/
		/*bit masking*/
		GPIOC->MODER &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOC->MODER |= (0b01<<(Copy_u8PinID*2))  ;


		/*set speed of the input pin*/
		/*bit masking*/
		GPIOC->OSPEEDR &= ~(0b11<<(Copy_u8PinID*2)) ;
		GPIOC->OSPEEDR |= (Copy_u8PinSpeed<<(Copy_u8PinID*2))  ;

		/*set type of output pin*/
		WRT_BIT(GPIOC->OTYPER , Copy_u8PinID , Copy_u8PinType) ;
		break ;

	}
}

//void GPIO_voidInitInputPin(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PullMode)
//{
//
//}

void GPIO_voidSetOutputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
	switch (Copy_u8PortID)
	{
	case GPIO_PORTA :
		WRT_BIT(GPIOA->ODR , Copy_u8PinID , Copy_u8Value);
		break ;


	case GPIO_PORTB :
		WRT_BIT(GPIOB->ODR , Copy_u8PinID , Copy_u8Value);
		break ;

	case GPIO_PORTC :
		WRT_BIT(GPIOC->ODR , Copy_u8PinID , Copy_u8Value);
		break ;
     }
}

//u8 GPIO_voidSetInputPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
//{
//
//}



