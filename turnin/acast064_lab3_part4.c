/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #4
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
	DDRC = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	int tempA = 0x00;
	int tempB = 0x00;
	/* Insert your solution below */
   	while (1) 
	{

		tempA = 0xF0 & PINA;
		tempB = 0x0F & PINA;

		PORTB = tempB;
		PORTC = tempA;
	}
}
