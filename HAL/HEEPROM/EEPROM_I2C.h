#ifndef _EEPROM_I2C_H_

/*************************Libraries***********************************/
#include "TWI.h"
#include <string.h>
#include <stdint.h>
#include <util\delay.h>
#include "main.h"

/*************************Definitions*********************************/								
#define EEPROM_ADDR 		0xA0	/*Slave Address to an I2C EEPROM-->A0 = 1 -- A2=A3=0*/
#define EEPROM_ADDRead 		0xA1	/*Slave Address to an I2C EEPROM-->A0 = 1 -- A2=A3=0*/
#define PAGE_SIZE 			32 		/*Size of Page Eual 32 Bytes												*/
#define PAGE_NUM  			128		/*NO.OF Pages Eual 128Page													*/
#define ADDR_BIT_PAGE 	5			/*Addresses	Pages start to bit 5-->log2(PAGE_SIZE)=5*/
#define ADDR_BUS_SIZE 	2		 	/*Address	BUS to EEPROM 2^12Bit ~~ 2Byte						*/
/*********************Function Definition******************************/
/*Detect & Correct OFFSET */
#define CHECK_OFFSET(value) 	if(value < PAGE_SIZE)(value = (PAGE_SIZE-1)) 		 	
/*************************Function************************************/

void EEPROM_VidInit (void);

void EEPROM_write_DataBace (DataBase Data[]);

void EEPROM_read_DataBace (DataBase Data[]);

void EEPROM_write_data_byte (uint16_t Address, uint8_t Data);

void EEPROM_write_data_bytes_per_page (uint16_t Page, uint8_t *Data, uint16_t Size);

uint8_t EEPROM_read_data_byte (uint16_t Address);

void EEPROM_read_data_bytes_per_page (uint16_t Page, uint8_t *Data, uint16_t Size);

void EEPROM_erase_data_per_page(uint16_t Page);

#endif /*_EEPROM_I2C_H_*/
