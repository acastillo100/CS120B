/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section:23
 *	Assignment: Lab #2  Exercise #1
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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	/* Insert your solution below */
   	while (1) {
    		tmpA = PINA;
		// if PA0 is 1, set PB1PB0 = 01, else = 10
		if (tmpA == 0x00) { // True if PA0 is 0 and PA1 is 0
			PORTB = 0x00; // Sets tmpB to bbbbbb00
							 // (clear rightmost 2 bits, then set to 00)
		}
		else if (tmpA == 0x01) { // True if PA0 is 1 and PA1 is 0
                        PORTB = 0x01; // Sets tmpB to bbbbbb01
                                                         // (clear rightmost 2 bits, then set to 01)
		}
		else if (tmpA == 0x02) { // True if PA0 is 0 and PA1 is 2
                        PORTB = 0x00; // Sets tmpB to bbbbbb00
                                                         // (clear rightmost 2 bits, then set to 00)
                }
		else if (tmpA == 0x03) { // True if PA0 is 1 and PA1 is 3
                        PORTB = 0x00; // Sets tmpB to bbbbbb00
                                                         // (clear rightmost 2 bits, then set to 00)
                }
		else {
			PORTB = 0x00; // Sets tmpB to bbbbbb10
							 // (clear rightmost 2 bits, then set to 00)
		}	
	}
    return 0;
}
