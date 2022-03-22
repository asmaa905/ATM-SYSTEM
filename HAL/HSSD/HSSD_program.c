/*
 * HSSD_program.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mina
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "HSSD_config.h"
#include "HSSD_interface.h"
#include "HSSD_private.h"

void HSSD_voidSetNumber(u8 copy_u8Number,u8 copy_u8Port,u8 copy_u8Type)
{
	switch(copy_u8Type)
	{
	case HSSD_CA_TYPE:
		switch(copy_u8Port)
		{
		case DIO_u8_PORTA:DIO_u8SetPortValue(DIO_u8_PORTA,CA_ptterns[copy_u8Number]);break;
		case DIO_u8_PORTB:DIO_u8SetPortValue(DIO_u8_PORTB,CA_ptterns[copy_u8Number]);break;
		case DIO_u8_PORTC:DIO_u8SetPortValue(DIO_u8_PORTC,CA_ptterns[copy_u8Number]);break;
		case DIO_u8_PORTD:DIO_u8SetPortValue(DIO_u8_PORTD,CA_ptterns[copy_u8Number]);break;
		}
		break;
	case HSSD_CC_TYPE:
		switch(copy_u8Port)
		{
		case DIO_u8_PORTA:DIO_u8SetPortValue(DIO_u8_PORTA,~CA_ptterns[copy_u8Number] << 1);break;
		case DIO_u8_PORTB:DIO_u8SetPortValue(DIO_u8_PORTB,~CA_ptterns[copy_u8Number] << 1);break;
		case DIO_u8_PORTC:DIO_u8SetPortValue(DIO_u8_PORTC,~CA_ptterns[copy_u8Number] << 1);break;
		case DIO_u8_PORTD:DIO_u8SetPortValue(DIO_u8_PORTD,~CA_ptterns[copy_u8Number] << 1);break;
		}
		break;
	}
}

void HSSD_BCD_voidSetNumber(u8 copy_u8Number,u8 copy_u8Port)
{
	switch(copy_u8Port)
	{
	case DIO_u8_PORTA:DIO_u8SetPortValue(DIO_u8_PORTA,copy_u8Number);break;
	case DIO_u8_PORTB:DIO_u8SetPortValue(DIO_u8_PORTB,copy_u8Number);break;
	case DIO_u8_PORTC:DIO_u8SetPortValue(DIO_u8_PORTC,copy_u8Number);break;
	case DIO_u8_PORTD:DIO_u8SetPortValue(DIO_u8_PORTD,copy_u8Number);break;
	}
}
