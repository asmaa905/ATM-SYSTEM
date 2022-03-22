/*
 * TWI.c
 * Source code of  The Two-Wire Serial Interface (TWI) is compatible with Phillips I2C protocol.
 * Created: 7/6/2021 12:07:18 AM
 *  Author: Ahmed H. Zakaria
 */ 
#include "TWI.h"

void TWI_InitM(void)
{
	TWSR &=~ 3;
	TWBR = 72; /***100000 Bit rate ##1.0KHz##***/
}

void TWI_StartM(void)
{
	TWCR = (1 <<TWINT) | (1 <<TWSTA) | (1 <<TWEN);
	while (!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8)!= TW_START);
}

void TWI_REPStartM(void)
{
	TWCR = (1 <<TWINT) | (1 <<TWSTA) | (1 <<TWEN);
	while (!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8)!= TW_REP_START);
}

void TMI_WriteA(uint8_t Address ,uint8_t typeTWI)
{
	TWDR = Address;
	TWCR = (1 <<TWINT) | (1 <<TWEN);
	while ((TWCR & (1 <<TWINT)) == 0);
	while( (TWSR & 0xF8) != typeTWI);
}

void TMI_WriteD(uint8_t Data ,uint8_t type)
{
	TWDR = Data;
	TWCR = (1 <<TWINT) | (1 <<TWEN);
	while (!(TWCR & (1 << TWINT)));
	while( (TWSR & 0xF8) != type);
}

void TWI_stop(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
void TWI_Init_S(uint8_t Addr)
{
	TWAR = Addr;
}

uint8_t TWI_Receive(void)
{
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & 0xf8) != TW_MR_DATA_ACK);
	return TWDR;
}

void TWI_ACK(void)
{
	while ((TWSR & 0xf8) != 0x60)
	{
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while(!(TWCR & (1<<TWINT)));
	}
}

uint8_t TWI_Read(uint8_t NACK0)
{
	if (NACK0){
		TWCR = (1 <<TWINT) | (1 <<TWEN);
		while ((TWCR & (1 <<TWINT)) == 0);
		while((TWSR & 0xF8) != TW_MR_DATA_NACK);
		return TWDR;
	}
	else{
		TWCR = (1 <<TWINT) | (1 <<TWEN) | (1 <<TWEA);
		while ((TWCR & (1 <<TWINT)) == 0);
		while((TWSR & 0xF8) != TW_MR_DATA_ACK);
		return TWDR;
	}
}
