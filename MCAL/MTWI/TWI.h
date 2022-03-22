/*
 * TWI.h
 *
 * Created: 7/6/2021 12:04:11 AM
 *  Author: Ahmed H. Zakaria
 */ 


#ifndef TWI_H_
#define TWI_H_

#include <stdint.h>
#include <avr/io.h>
#include <util/twi.h>
/*************************Function of Two-Wire Serial Interface***********************************/
void TWI_InitM(void);
void TWI_StartM(void);
void TWI_REPStartM(void);
void TMI_WriteA(uint8_t Address ,uint8_t typeTWI);
void TMI_WriteD(uint8_t Data ,uint8_t type);
void TWI_stop(void);
void TWI_Init_S(uint8_t Addr);
uint8_t TWI_Receive(void);
void TWI_ACK(void);
uint8_t TWI_Read(uint8_t NACK0);

#endif /* TWI_H_ */
