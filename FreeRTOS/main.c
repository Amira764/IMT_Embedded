#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "FreeRTOS.h"
#include "task.h"
#include "GIE_int.h"
#include "EXTI_int.h"

void led1(void *ptr)
{
	static u8 i=0;
	while(1)
	{
		if(i==0)
		{
			DIO_SetPinValue(0,PIN_0,HIGH);
			i=1;
		}
		else
		{
			DIO_SetPinValue(0,PIN_0,LOW);
			i=0;
		}
		vTaskDelay(1000);
	}
}

void led2(void *ptr)
{
	static u8 i=0;
	while(1)
	{
		if(i==0)
		{
			DIO_SetPinValue(0,PIN_1,HIGH);
			i=1;
		}
		else
		{
			DIO_SetPinValue(0,PIN_1,LOW);
			i=0;
		}
		vTaskDelay(3000);
	}
}

void led3(void *ptr)
{
	static u8 i=0;
	while(1)
	{
		if(i==0)
		{
			DIO_SetPinValue(0,PIN_2,HIGH);
			i=1;
		}
		else
		{
			DIO_SetPinValue(0,PIN_2,LOW);
			i=0;
		}
		vTaskDelay(5000);
	}
}

void func(void);

void main(void)
{
	DIO_SetPortDirection(0,PortOut);

	xTaskCreate(led1,NULL,configMINIMAL_STACK_SIZE,NULL,0,NULL);
	xTaskCreate(led2,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
	xTaskCreate(led3,NULL,configMINIMAL_STACK_SIZE,NULL,2,NULL);

	vTaskStartScheduler();

	GIE_Enable();

	EXTI_Enable(EXTI0);
	EXTI_SetTriggerMode();

	DIO_SetPinDirection(PORTD,PIN_2,Input);
	DIO_SetPinValue(PORTD,PIN_2,HIGH);
	u8 button = 0;
	while(1)
	{
		button = DIO_GetPinValue(PORTD,PIN_2);
		if (button ==0)
		{
			EXTI0_CallBackFunc(func);
		}
	}
}

void func(void)
{
	u8 button = 0;
	while(1)
	{
		button = DIO_GetPinValue(PORTD,PIN_2);
		if (button ==1)
		{
			break;
		}
	}
}