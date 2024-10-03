/*
 * main.c
 *
 *  Created on: Oct 2, 2024
 *      Author: hp
 */

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KPD_int.h"
#include "RTC_int.h"
#include "stopwatch_int.h"

#define TimeClock  1
#define Alarm  	   2
#define StopWatch  3
#define CountDown  4

void main(void)
{
	//inits
	TWI_voidMasterInit();
	RTC_voidInit();
	LCD_init();
	KPD_init();

	//current node
	RTC_val * current;
	u8 mode = 0;

	//print welcome messages and start program

	//choose mode
	mode = KPD_GetKey();
	switch (mode)
	{
		case TimeClock:

			break;
		case Alarm:

			break;
		case StopWatch:

			break;
		case CountDown:

			break;
		default:
			break;
	}
}
