/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #5
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
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;
	int tempB = 0x00;
	int tempD = 0x00;
	int tempF = 0x0000;
	/* Insert your solution below */
   	while (1) 
	{

		tempB = 0x00;
		tempD = 0x00;
		tempF = 0x0000;
		PORTB = 0x00;
		tempB = 0x00 | PINB;
		tempD = 0x00 | PIND;
		tempF = (tempD << 1 ) | (tempB & 0x01); //Creates our 9 bit number for the if statements to check

		if(tempF >= 0x46 && tempF <= 0x1FF)
			PORTB = PORTB | 0x01; //0x01 will be put in B's 2nd slot
		else if(tempF >= 0x05 && tempF < 0x46)
			PORTB = PORTB | 0x02; //0x02 will be in B's 3rd slot
		else if(tempF < 0x05)
			PORTB = PORTB | PORTB;

	}
}
