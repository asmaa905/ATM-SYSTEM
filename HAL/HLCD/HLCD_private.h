/*
 * HLCD_private.h
 *
 *  Created on: Oct 12, 2021
 *      Author: Mina
 */

#ifndef HLCD_HLCD_PRIVATE_H_
#define HLCD_HLCD_PRIVATE_H_


#define FUNCTION_SET_8BIT_MODE_2LINES	0b00111000
#define FUNCTION_SET_8BIT_MODE_1LINES	0b00110000
#define FUNCTION_SET_4BIT_MODE_2LINES	0b00101000
#define FUNCTION_SET_4BIT_MODE_1LINES	0b00100000

#define DISPLAY_ON_CURSOR_ON_BLINK		0b00001111
#define DISPLAY_ON_CURSOR_ON_NOBLINK	0b00001110
#define DISPLAY_ON_CURSOR_OFF_NOBLINK	0b00001100
#define DIPLAY_OFF						0b00001000

#define CLEAR_DISPLAY					0b00000001

#define ENTRY_MODE_SET_INCREASE			0b00000110
#define ENTRY_MODE_SET_DECREASE			0b00000100

#define SET_DDRAM_ADDRESS				0x80
#define HLCD_SECOND_ROW_ADDRESS_OFFSET   0x40

#define SET_CGRAM_ADDRESS				0x40

#endif /* HLCD_HLCD_PRIVATE_H_ */