#include"STD_TYPES.h"

#include"DIO_Interface.h"
#include"HLCD_interface.h"
#include"HKEYPAD_interface.h"
#include"FreeRTOS.h"
#include"task.h"
#include"semphr.h"
#include"queue.h"
#include "EEPROM_I2C.h"
#include "main.h"

static u8 Is_Printed = 0;
static u8 flagToWait=0;
static u8 Counter=0;


DataBase CustomersWrite[5]={{1234,1324,5000},
		{4564,2536,50000},
		{8594,4562,10000},
		{3214,8596,6000},
		{0,0,0}
};
DataBase Customers[5];
xSemaphoreHandle LCDSem;
xSemaphoreHandle CardSem;
xSemaphoreHandle PassSem;
//xSemaphoreHandle MenuSem;

xQueueHandle   ID_KPD_Message;
xQueueHandle   PASS_KPD_Message;
xQueueHandle   ID_Index_Message;

void APP_VidWelcomeTask(void*pv);
void APP_VidGet_ID_From_Keypad(void *pv);
void APP_VidCheckOnID(void *pv);
void APP_VidGet_PASS_From_Keypad(void*pv);
void APP_VidCheckOnPASS(void *pv);
//void APP_VidView_Menu(void *pv);


void WaitingForLCD(u8 *FlagToWait, u8 *Counter){
	if (*FlagToWait==1){
		*Counter+=1;
	}
	else {
		return;
	}
	if(*Counter == 20){
		xSemaphoreGive(LCDSem);
		Is_Printed=0;
		*Counter=0;
		*FlagToWait=0;
		return;
	}
}
void main(void)
{

	DIO_voidInit();
	HLCD_voidInit();
	HKEYPAD_voidInit();
	EEPROM_VidInit();
	EEPROM_write_DataBace (CustomersWrite);
	EEPROM_read_DataBace (Customers);
	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_INPUT_PULLED_UP);

	vSemaphoreCreateBinary(LCDSem);
	CardSem = xSemaphoreCreateCounting(5,1);
	PassSem = xSemaphoreCreateCounting(5,1);


	ID_KPD_Message=xQueueCreate(1,sizeof(u16));
	PASS_KPD_Message=xQueueCreate(1,sizeof(u16));
	ID_Index_Message=xQueueCreate(1,sizeof(u8));


	xTaskCreate(APP_VidWelcomeTask,NULL,150,NULL,5,NULL);
	xTaskCreate(APP_VidGet_ID_From_Keypad,NULL,150,NULL,1,NULL);
	xTaskCreate(APP_VidCheckOnID,NULL,150,NULL,1,NULL);
	xTaskCreate(APP_VidGet_PASS_From_Keypad,NULL,150,NULL,1,NULL);
	xTaskCreate(APP_VidCheckOnPASS,NULL,150,NULL,1,NULL);
	//xTaskCreate(APP_VidView_Menu,NULL,300,NULL,4,NULL);

	xSemaphoreTake(CardSem,10);
	xSemaphoreTake(PassSem,10);
	//xSemaphoreTake(MenuSem,10);

	vTaskStartScheduler();

	while(1)
	{
	}
	
}
void APP_VidWelcomeTask(void*pv)
{
	u8 Loc_u8ButtonState=1;
	u8 LCDSemState=0;
	while(1)
	{
		LCDSemState=xSemaphoreTake(LCDSem,10);
		if(LCDSemState==pdPASS)
		{
			if (Is_Printed == 0){
				HLCD_voidClearDisplay();
				HLCD_voidSendString("NTI Bank");
				Is_Printed=1;
			}
			DIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,&Loc_u8ButtonState);
			if(Loc_u8ButtonState == 0)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("Enter ID:");
				HLCD_voidSetPosition(1,6);
				xSemaphoreGive(CardSem);
			}
			else
			{
				xSemaphoreGive(LCDSem);
			}
		}
		else
		{
			/*Do Nothing*/
		}
		vTaskDelay(100);
	}

}
void APP_VidGet_ID_From_Keypad(void *pv)
{
	u8 Loc_u8CardSemState;
	u8 Loc_u8KeyPressed=HKEYPAD_NO_PRESSED_KEY;
	u8 ID[5]={HKEYPAD_NO_PRESSED_KEY};
	u16 Loc_u16ID;
	u8 Loc_Count=0;
	while(1)
	{
		Loc_u8CardSemState=xSemaphoreTake(CardSem,10);
		if(Loc_u8CardSemState==pdPASS)
		{
			Loc_u8KeyPressed=HKEYPAD_u8GetPressedKey();
			if ((Loc_u8KeyPressed != 'E') && (Loc_Count < 5)){
				if(Loc_u8KeyPressed != HKEYPAD_NO_PRESSED_KEY){
					HLCD_voidSendNumber(Loc_u8KeyPressed);
					ID[Loc_Count]=Loc_u8KeyPressed;
					Loc_Count++;
				}
				xSemaphoreGive(CardSem);
			}
			else if(Loc_u8KeyPressed == 'E' && (Loc_Count == 4)) {
				Loc_u16ID=((ID[0])*1000)+((ID[1])*100)+((ID[2])*10)+((ID[3]));
				xQueueSend(ID_KPD_Message,&Loc_u16ID,10);
				Loc_Count=0;
			}
			else{
				// ERROR ENTRY -> GO BACK TO HOME PAGE
				HLCD_voidClearDisplay();
				HLCD_voidSendString("INVALID ENTRY...");
				Loc_Count=0;
				flagToWait=1;
			}
		}
		WaitingForLCD(&flagToWait,&Counter);
		vTaskDelay(100);
	}
}
void APP_VidCheckOnID(void *pv)
{
	u16 ID_Message;
	u8 Loc_u8MessageState;
	u8 Loc_u8Count=0;
	u8 Loc_u8Flag=0;
	while(1)
	{
		Loc_u8MessageState=xQueueReceive(ID_KPD_Message,&ID_Message,10);
		if(Loc_u8MessageState==pdPASS)
		{

			while(Customers[Loc_u8Count].ID!=0)
			{
				if(Customers[Loc_u8Count].ID==ID_Message)
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Enter Pass:");
					HLCD_voidSetPosition(1,6);
					Loc_u8Flag=1;
					xQueueSend(ID_Index_Message,&Loc_u8Count,10);
					xSemaphoreGive(PassSem);
					break;
				}
				else
				{
					//Do Nothing
				}
				Loc_u8Count++;
			}
			Loc_u8Count=0;
			if(Loc_u8Flag==0)
			{
				HLCD_voidClearDisplay();
				HLCD_voidSendString("ID IS NOT VALID..");
				flagToWait=1;
			}
			else
			{
				//Do Nothing
			}
		}
		WaitingForLCD(&flagToWait,&Counter);
		vTaskDelay(200);
	}
}
void APP_VidGet_PASS_From_Keypad(void *pv)
{
	u8 Loc_u8PASSSemState;
	u8 Loc_u8KeyPressed=HKEYPAD_NO_PRESSED_KEY;
	u8 PASS[5]={HKEYPAD_NO_PRESSED_KEY};
	u16 Loc_u16PASS;
	u8 Loc_Count=0;

	while(1)
	{
		Loc_u8PASSSemState=xSemaphoreTake(PassSem,10);
		if(Loc_u8PASSSemState==pdPASS)
		{
			Loc_u8KeyPressed=HKEYPAD_u8GetPressedKey();
			if ((Loc_u8KeyPressed != 'E') && (Loc_Count < 5)){
				if(Loc_u8KeyPressed != HKEYPAD_NO_PRESSED_KEY){
					//HLCD_voidSendNumber(Loc_u8KeyPressed);
					HLCD_voidSendData('*');
					PASS[Loc_Count]=Loc_u8KeyPressed;
					Loc_Count++;
				}
				xSemaphoreGive(PassSem);
			}
			else if(Loc_u8KeyPressed == 'E' && (Loc_Count == 4)) {
				Loc_u16PASS=((PASS[0])*1000)+((PASS[1])*100)+((PASS[2])*10)+((PASS[3]));
				xQueueSend(PASS_KPD_Message,&Loc_u16PASS,10);
				Loc_Count=0;
			}
			else{
				// ERROR ENTRY -> GO BACK TO HOME PAGE
				HLCD_voidClearDisplay();
				HLCD_voidSendString("INVALID ENTRY...");
				Loc_Count=0;
				flagToWait=1;
			}
		}
		else
		{
			/*Do Nothing*/
		}
		WaitingForLCD(&flagToWait,&Counter);
		vTaskDelay(100);
	}
}
void APP_VidCheckOnPASS(void *pv){
	u16 PASS_Message;
	u8 Loc_u8IDMessageState;
	u8 Loc_u8PASSMessageState;
	u8 Loc_u8Count=0;
	while(1)
	{
		Loc_u8PASSMessageState=xQueueReceive(PASS_KPD_Message,&PASS_Message,10);
		if(Loc_u8PASSMessageState==pdPASS)
		{
			Loc_u8IDMessageState=xQueueReceive(ID_Index_Message,&Loc_u8Count,10);
			if(Loc_u8IDMessageState==pdPASS)
			{
				if(Customers[Loc_u8Count].Password==PASS_Message)
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Please wait....");
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Your balance is:");
					HLCD_voidSetPosition(1,6);
					HLCD_voidSendNumber(Customers[Loc_u8Count].Balance);
					flagToWait=1;

				}
				else
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendString("Pass IS NOTVALID");
					flagToWait=1;
				}
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
		WaitingForLCD(&flagToWait,&Counter);
		vTaskDelay(200);
	}
}
/*void APP_VidView_Menu(void *pv){
	u8 Loc_u8PassState;
	u8 Loc_u8KeyPressed=HKEYPAD_NO_PRESSED_KEY;
	while(1){
		Loc_u8PassState=xSemaphoreTake(MenuSem,10);
		if(Loc_u8PassState == pdPASS){
			HLCD_voidSendString("1-balance");
			HLCD_voidSetPosition(0,10);
			HLCD_voidSendString("2-wd");
			HLCD_voidSetPosition(1,6);
			HLCD_voidSendString("3-Exit");
			Loc_u8KeyPressed=HKEYPAD_u8GetPressedKey();
			if(Loc_u8KeyPressed == 1)
			{
				//xSemaphoreGive(BalanceSem);
				xSemaphoreGive(LCDSem);
			}
			else if (Loc_u8KeyPressed == 2)
			{
				//xSemaphoreGive(WithDrawSem);
				xSemaphoreGive(LCDSem);
			}
			else if (Loc_u8KeyPressed == 3)
			{
				xSemaphoreGive(LCDSem);
			}
			else {
				//error
			}

		}
	}
	vTaskDelay(100);
}
 */
