/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section:23
 *	Assignment: Lab #2  Exercise #4
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
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	int cntavail = 0x000000; // Temporary variable to hold the value of weight

	/* Insert your solution below */
   	while (1) {
		PORTD = 0x00;
    		cntavail = 0x000000;
		cntavail = PINA + PINB + PINC;
		if (cntavail > 0x008C) { //True if A+B+C > 140kg
			PORTD = PORTD | 0x01; 
		}
		if (((PINA - PINC) > 0X50) || ((PINC - PINA) > 0x50)) { // True if the difference between PINA and PINC is > 80kg
                        PORTD = PORTD | 0x02;
		}
		PORTD = (cntavail << 2) | PORTD;
	}
    return 0;
}
