/*
 * HLED_interface.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Mina
 */

#ifndef HLED_HLED_INTERFACE_H_
#define HLED_HLED_INTERFACE_H_

#define LED0 0
#define LED1 1
#define LED2 2

void HLED_voidLedInit(u8 led_num);
void HLED_voidTurnON(u8 led_num);
void HLED_voidTurnOFF(u8 led_num);
void HLED_voidTogLed(u8 led_num);

#endif /* HLED_HLED_INTERFACE_H_ */
