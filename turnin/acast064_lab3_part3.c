/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	int countA = 0x00;
	int counter = 0x00;
	int seatbelt = 0x00;
	int tempA = 0x00;
	/* Insert your solution below */
   	while (1) 
	{
		countA = 0x00;
		counter = 0x00;
		seatbelt = 0x00;
		countA = countA | PINA;
		tempA = countA;
		tempA = tempA << 0x01;
		
		for (int i = 0; i < 3; i++)
		{
			if ((tempA & 0x80) == 0x80)
			{
				counter = counter+1;
			}
			if (i == 0 && counter == 0)
				seatbelt = 0x01;
			tempA = tempA << 0x01;
		}
		
		if ((countA & 0x00) == 0x00)
		{
			if (seatbelt == 0x01 && counter == 0x02)
		       		PORTC = 0x80;
			else
				PORTC = 0x00;
		}
		if (((countA & 0x01) == 0x01) || ((countA & 0x02) == 0x02))
		{
			if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xA0;
                        else
                                PORTC = 0x20;
		}
		if (((countA & 0x03) == 0x03) || ((countA & 0x04) == 0x04))
		{	if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xB0;
                        else
				PORTC = 0x30;
		}
		if (((countA & 0x05) == 0x05) || ((countA & 0x06) == 0x06))
                {       if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xB8;
                        else
				PORTC = 0x38;
		}
		if (((countA & 0x07) == 0x07) || ((countA & 0x08) == 0x08) || ((countA & 0x09) == 0x09))
                {       if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xBC;
                        else
				PORTC = 0x3C;
		}
		if (((countA & 0x0A) == 0x0A) || ((countA & 0x0B) == 0x0B) || ((countA & 0x0C) == 0x0C))
                {       if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xBE;
                        else
				PORTC = 0x3E;
		}
		if (((countA & 0x0D) == 0x0D) || ((countA & 0x0E) == 0x0E) || ((countA & 0x0F) == 0x0F))
                {       if (seatbelt == 0x01 && counter == 0x02)
                                PORTC = 0xBF;
                        else
				PORTC = 0x3F;
		}
		if (countA < 0x00)
		{
			PORTC = 0xFF;	
			printf("This is an error. Input not accepted.");
		}
	}
}
