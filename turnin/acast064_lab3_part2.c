/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #2
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
	/* Insert your solution below */
   	while (1) 
	{
		countA = 0x00;
        	//countB = 0x00;
		//counter = 0x00;
		countA = countA | PINA;
		//countB = countB | PINB;
		//tempA = countA;
		//tempB = countB;
		if (countA == 0x00)
		       PORTC = 0x00;
		if (countA > 0x00 && countA <= 0x02)
			PORTC = 0x20;
		if (countA > 0x02 && countA <= 0x04)
			PORTC = 0x30;
		if (countA > 0x04 && countA <= 0x06)
			PORTC = 0x38;
		if (countA > 0x06 && countA <= 0x09)
			PORTC = 0x3C;
		if (countA > 0x09 && countA <= 0x0C)
			PORTC = 0x3E;
		if (countA > 0x0C && countA <= 0x0F)
			PORTC = 0x3F;
		if (countA > 0x0F || countA < 0x00)
		{
			PORTC = 0xFF;	
			printf("This is an error. Input not accepted.");
		}
	}
}
