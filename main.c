/*
 * main.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Eng Hamada Ahmed
 */


/*************************LIB**************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

/*************************MCAL*************************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Config.h"
#include "MCAL/DIO/DIO_Private.h"
#include "MCAL/EXTI/EXTI_Private.h"

/*************************HAL**************************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
/*************************Delay*************************/
#include <util/delay.h>




void Handle_EXTI0(void){
	             /*light of first four LEDs in PORTC for 3 seconds*/
   GIE_VidEn();
	LCD_vid_DisplayClear();
	LCD_vid_GoTo(0,3);
	LCD_vid_SendString("Welcome!");
	LCD_vid_GoTo(1,0);
	LCD_vid_SendString("EXTI 0 Handle..");
	DIO_Vid_SetPinValue(Port_C,pin0,PinHigh);
	DIO_Vid_SetPinValue(Port_C,pin1,PinHigh);
	DIO_Vid_SetPinValue(Port_C,pin2,PinHigh);
	DIO_Vid_SetPinValue(Port_C,pin3,PinHigh);

	_delay_ms(2000);

	DIO_Vid_SetPinValue(Port_C,pin0,PinLow);
	DIO_Vid_SetPinValue(Port_C,pin1,PinLow);
	DIO_Vid_SetPinValue(Port_C,pin2,PinLow);
	DIO_Vid_SetPinValue(Port_C,pin3,PinLow);

	LCD_vid_DisplayClear();
/*
if (READ_BIT(GIFR , GIFR_INTF1))
		{
			LCD_vid_DisplayClear() ;
			LCD_vid_GoTo(0,3);
			LCD_vid_SendString("Welcome!");
			LCD_vid_GoTo(1,0);
			LCD_vid_SendString("EXTI 1 Handle..");

			SET_BIT(GIFR , GIFR_INTF1) ;

		}
		*/
//LCD_vid_DisplayClear();

}

void Handle_EXTI1(void){
	             /* flash of Second four LEDs in PORTC every 0.7 second */

	/* enable global interrupt */
	GIE_VidEn();

	/*clear EXTI 1 flag */
	SET_BIT(GIFR, GIFR_INTF1);

		LCD_vid_DisplayClear();
		LCD_vid_GoTo(0,3);
		LCD_vid_SendString("Welcome!");
		LCD_vid_GoTo(1,0);
		LCD_vid_SendString("EXTI 1 Handle..");


	DIO_Vid_SetPinValue(Port_C,pin0,PinHigh);
	_delay_ms(1000);
	DIO_Vid_SetPinValue(Port_C,pin0,PinLow);

	LCD_vid_GoTo(0,3);
	LCD_vid_SendString("Welcome!");
	LCD_vid_GoTo(1,0);
	LCD_vid_SendString("EXTI 1 Handle..");

	DIO_Vid_SetPinValue(Port_C,pin1,PinHigh);
	_delay_ms(1000);
	DIO_Vid_SetPinValue(Port_C,pin1,PinLow);
	LCD_vid_GoTo(0,3);
	LCD_vid_SendString("Welcome!");
	LCD_vid_GoTo(1,0);
	LCD_vid_SendString("EXTI 1 Handle..");

	DIO_Vid_SetPinValue(Port_C,pin2,PinHigh);
	_delay_ms(1000);
	DIO_Vid_SetPinValue(Port_C,pin2,PinLow);
	LCD_vid_GoTo(0,3);
	LCD_vid_SendString("Welcome!");
	LCD_vid_GoTo(1,0);
	LCD_vid_SendString("EXTI 1 Handle..");

	DIO_Vid_SetPinValue(Port_C,pin3,PinHigh);
	_delay_ms(1000);
	DIO_Vid_SetPinValue(Port_C,pin3,PinLow);
	LCD_vid_GoTo(0,3);
	LCD_vid_SendString("Welcome!");
	LCD_vid_GoTo(1,0);
	LCD_vid_SendString("EXTI 1 Handle..");

	LCD_vid_DisplayClear();


}

int main(void){


    /*LEDs Initialization*/
DIO_Vid_SetPortDirection(Port_C,output);   //for 4 LEDs: first 4 bins on PORTC for EXTI0 & EXTI1
//	DIO_Vid_SetPortValue(Port_C,0x00);

	/*Modules Initializations*/

                    /*LCD Initializations*/
	DIO_Vid_SetPortDirection(Port_B,output);
	DIO_Vid_SetPinDirection(Port_A,pin5,output);
	DIO_Vid_SetPinDirection(Port_A,pin6,output);
	DIO_Vid_SetPinDirection(Port_A,pin7,output);


		DIO_Vid_SetPinDirection(Port_D,pin2,input);  //INT0
		DIO_Vid_SetPinDirection(Port_D,pin3,input);  //INT1

		   /*Interrupts Initialization*/
		GIE_VidEn();
		EXTI_voidInit();

		 EXTI_u8Int0SetCallBack(Handle_EXTI0);
		 EXTI_u8Int1SetCallBack(Handle_EXTI1);

		 LCD_Vid_Init();

		 LCD_vid_DisplayClear();

while(1){

			 LCD_vid_GoTo(0,0);
			 LCD_vid_SendString("Welcome to MP4!");

			 LCD_vid_GoTo(1,3);
			 LCD_vid_SendString("Wazeefa_Tech");
}

	return 0;
}

