/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x0000;
	int countA = 0x00;
	int countB = 0x00;
	int counter = 0x00;
	int tempA = 0x00;
	int tempB = 0x00;
	/* Insert your solution below */
   	while (1) 
	{
		countA = 0x00;
        	countB = 0x00;
		counter = 0x00;
		countA = countA | PINA;
		countB = countB | PINB;
		tempA = countA;
		tempB = countB;
		for (int i = 0; i < countA; i++)
		{
			if ((tempA & 0x01) == 0x01)
			{
				counter = counter+1;
			}
			tempA = tempA >> 0x01;
		}
		for (int i = 0; i < countB; i++)
                {
			 if ((tempB & 0x01) == 0x01)
			 {
                                counter = counter+1;
			 }
                        tempB = tempB >> 0x01;
                }

		//countA = PINA & 0xFF;
		//countB = PINB & 0xFF;

		PORTC = counter;
	}
}
