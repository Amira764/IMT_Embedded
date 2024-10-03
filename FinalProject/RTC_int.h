/*
 * RTC_int.h
 *
 *  Created on: Oct 2, 2024
 *      Author: hp
 */

#ifndef RTC_INT_H_
#define RTC_INT_H_

#include "RTC_prv.h"

// struct or arrays
typedef struct {
	u8 u8Seconds;
	u8 u8Minutes;
	u8 u8Hours;
	u8 u8DayOfWeek;
	u8 u8Days;
	u8 u8Months;
	u8 u8Years;
} RTC_val;

//init
void RTC_voidInit(void);

//to set time
void RTC_voidSetSec(RTC_val* rtc);
void RTC_voidSetMin(RTC_val* rtc);
void RTC_voidSetHour(RTC_val* rtc);

//to set date
void RTC_voidSetYr(RTC_val* rtc);
void RTC_voidSetMonth(RTC_val* rtc);
void RTC_voidSetDay(RTC_val* rtc);
void RTC_voidSetWeekDay(RTC_val* rtc);

//getters
u8 RTC_voidGetSec(void);
u8 RTC_voidGetMin(void);
u8 RTC_voidGetHour(void);

u8 RTC_voidGetYr(void);
u8 RTC_voidGetMonth(void);
u8 RTC_voidGetDay(void);
u8 RTC_voidGetWeekDay(void);

//Converters > display to user the decimal value lol
u8 DEC_to_BCD(u8);
u8 BCD_to_DEC(u8);

//I2C Communication functions
void RTC_Write(u8 Copy_u16RegAddress, u8 Copy_u8Data);
u8 RTC_Read(u8 Copy_u16RegAddress);

#endif /* RTC_INT_H_ */
