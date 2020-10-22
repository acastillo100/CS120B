/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
//#include "RIMS.h"
#endif

enum ON_States { ON_Start, ON_B0_On, ON_B1_On } ON_State;

void TickFct_On()
{
  switch(ON_State) {   // Transitions
     case ON_Start:  // Initial transition
        ON_State = ON_B0_On;
        break;

     case ON_B0_On:
        if ((PINA & 0x01) != 0x01) {
           ON_State = ON_B0_On;
        }
        if ((PINA & 0x01) == 0x01) {
           ON_State = ON_B1_On;
        }
        break;

     case ON_B1_On:
        if ((PINA & 0x01) == 0x01) {
           ON_State = ON_B0_On;
        }
        if ((PINA & 0x01) != 0x01) {
           ON_State = ON_B1_On;
        }
        break;

     default:
        ON_State = ON_Start;
        break;
  } // Transitions

  switch(ON_State) {   // State actions
     case ON_Start:
        break;

     case ON_B0_On:
        PORTB = 0x01;
        break;

     case ON_B1_On:
	PORTB = 0x02;
	break;

     default:
        break;
   } // State actions
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	PORTB = 0x00;
	ON_State = ON_Start;

    while (1) {
	TickFct_On();
    }
return 0;
}
