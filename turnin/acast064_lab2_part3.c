/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section:23
 *	Assignment: Lab #2  Exercise #3
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
	unsigned char cntavail = 0x00; // Temporary variable to hold the value of A

	/* Insert your solution below */
   	while (1) {
    		cntavail = PINA;
		if (cntavail == 0x01 || cntavail == 0x02 || cntavail == 0x04 || cntavail == 0x08) { // True if only PA0 or PA1 or PA2 or PA3 is 1 
			PORTC = 0x03; 
			printf("The number of parking spaces available is %c.", PORTC);
		}
		else if (cntavail == 0x03 || cntavail == 0x05 || cntavail == 0x06 || cntavail == 0x9 || cntavail == 0x0A || cntavail == 0x0C) { // True if only two bits of the lower half of PA are 1
                        PORTC = 0x02;
			printf("The number of parking spaces available is %c.", PORTC);
		}
		else if (cntavail == 0x07 || cntavail == 0x0B || cntavail == 0x0D || cntavail == 0x0E) { // True if three of the lower half bits of PA are 1
                        PORTC = 0x01;
                        printf("The number of parking spaces available is %c.", PORTC);
                }
		else if (cntavail == 0x0F) { // True if all 4 lower bits of PA are 1
                        PORTC = 0x40; 
			printf("The number of parking spaces available is %c.", PORTC >> 4);
                }
		else if(cntavail == 0x00) { //True iff all 4 lower bits of PA are 0
			PORTC = 0x04;
			printf("The number of parking spaces available is %c.", PORTC);
		}	
		else{
			PORTC = 0xFF;
			printf("The number of parking spaces available is an error %c.", PORTC);
		}
	}
    return 0;
}
