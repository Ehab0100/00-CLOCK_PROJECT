/*
 * main.c
 *
 *  Created on: 11 Aug 2023
 *      Author: ehab
 */


#define F_CPU 8000000UL
#include <util/delay.h>
#include "../HAL/Seven_SEG/HSSD.h"


int main()
{
	HSSD_voidInit(MDIO_PORTA);
	HSSD_voidInit(MDIO_PORTB);
	HSSD_voidInit(MDIO_PORTC);
	HSSD_voidInit(MDIO_PORTD);


	volatile u8 L_u8counter[4]={0};


	while(1)
	{

		HSSD_voidDisplayNUM(MDIO_PORTA,L_u8counter[0]++);

		HSSD_voidDisplayNUM(MDIO_PORTB,L_u8counter[1]);

		HSSD_voidDisplayNUM(MDIO_PORTC,L_u8counter[2]);

		HSSD_voidDisplayNUM(MDIO_PORTD,L_u8counter[3]);

		for(u8 counter=0;counter<60 ;counter++)
			{
				MDIO_voidTogglePinValue(MDIO_PORTA,7);
				_delay_ms(1);
			}


		if(L_u8counter[0] > 9)
		{
			L_u8counter[0]=0;
			L_u8counter[1]++;
		}

		if(L_u8counter[1] > 5)
		{
			L_u8counter[1]=0;
			L_u8counter[2]++;
		}

		if(L_u8counter[2] > 9)
		{
			L_u8counter[2]=0;
			L_u8counter[3]++;
		}

		if(L_u8counter[2] == 4 && L_u8counter[3] == 2)
		{
			L_u8counter[2]=0;
			L_u8counter[3]=0;
		}



	}
}
