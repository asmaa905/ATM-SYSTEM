#include "EEPROM_I2C.h"

#define NO_OF_CUSTOMERS 5



void EEPROM_VidInit (void)
{
	TWI_InitM();
}

void EEPROM_write_DataBace (DataBase Data[])
{
	uint16_t EepromCounterW = 0;
	EEPROM_write_data_byte (EepromCounterW++,NO_OF_CUSTOMERS);
	for(uint8_t i = 0;i < NO_OF_CUSTOMERS;i++)
	{
		/*Update IDs Customers*/
		EEPROM_write_data_byte (EepromCounterW++,Data[i].ID >> 8);
		EEPROM_write_data_byte (EepromCounterW++,Data[i].ID);
		/*Update Passwords Customers*/
		EEPROM_write_data_byte (EepromCounterW++,Data[i].Password >> 8);
		EEPROM_write_data_byte (EepromCounterW++,Data[i].Password);
		/*Update Balance Customers*/
		EEPROM_write_data_byte (EepromCounterW++,Data[i].Balance >> 8);
		EEPROM_write_data_byte (EepromCounterW++,Data[i].Balance);
	}
}

void EEPROM_read_DataBace (DataBase Data[])
{
	uint16_t CounterR = 0;
	for(uint8_t i = 0;i < NO_OF_CUSTOMERS;i++)
	{
		/*Update IDs Customers*/
		Data[i].ID = (EEPROM_read_data_byte (++CounterR) << 8) | EEPROM_read_data_byte (++CounterR);
		/*Update Passwords Customers*/
		Data[i].Password = (EEPROM_read_data_byte (++CounterR) << 8) | EEPROM_read_data_byte (++CounterR);
		/*Update Balance Customers*/
		Data[i].Balance = (EEPROM_read_data_byte (++CounterR) << 8) | EEPROM_read_data_byte (++CounterR);
	}
}


uint16_t EEPROM_determine_size(uint16_t Size, uint16_t Offset)
{
	uint16_t Check_Size = Size + Offset;
	/*Check Size smaller than Size EEPROM*/
	(Check_Size < PAGE_SIZE)?(Check_Size = Size):(Check_Size = PAGE_SIZE-Offset);
	return Check_Size;
}

void EEPROM_write_data_byte (uint16_t Address, uint8_t Data)
{
	TWI_StartM();
	TMI_WriteA(EEPROM_ADDR, 	TW_MT_SLA_ACK);
	TMI_WriteD(Address >> 8,    TW_MT_DATA_ACK);
	TMI_WriteD(Address, 		TW_MT_DATA_ACK);
	TMI_WriteD(Data, 	        TW_MT_DATA_ACK);
	TWI_stop();							/*Withing Next Write*/
	_delay_us(1);
}

void EEPROM_write_data_bytes_per_page (uint16_t Page, uint8_t *Data, uint16_t Size)
{
	uint16_t Address = Page * PAGE_SIZE;
	for(uint8_t i = 0;i < Size;i++)
	{
		EEPROM_write_data_byte (Address+i, Data[i]);
	}
}

uint8_t EEPROM_read_data_byte (uint16_t Address)
{
	uint8_t Data;
	TWI_StartM();
	TMI_WriteA(EEPROM_ADDR, TW_MT_SLA_ACK);
	TMI_WriteD(Address >> 8, TW_MT_DATA_ACK);
	TMI_WriteD(Address, TW_MT_DATA_ACK);
	TWI_REPStartM();
	TMI_WriteA(EEPROM_ADDRead, TW_MR_SLA_ACK);
	Data = TWI_Read(1);
	TWI_stop();							/*Withing Next Write*/
	_delay_us(1);
	return Data;
}

void EEPROM_read_data_bytes_per_page (uint16_t Page, uint8_t *Data, uint16_t Size)
{
	uint16_t Address = Page * PAGE_SIZE;
	for(uint8_t i = 0;i < Size;i++)
	{
		Data[i] = EEPROM_read_data_byte(Address+i);
	}
}

void EEPROM_erase_data_per_page (uint16_t Page)
{
	uint8_t data[PAGE_SIZE];
	memset(data,0xFF,PAGE_SIZE);	 /*Write the Data to Fills the Buffer*/
	/*I2C Write the Data to the EEPROM*/
	EEPROM_write_data_bytes_per_page (Page,data,PAGE_SIZE);
}
