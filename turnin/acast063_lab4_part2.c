/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #4  Exercise #2
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

enum IN_States { IN_Init, IN_Start, IN_Increment, IN_Decrement, IN_Reset } IN_State;

void TickFct_In()
{
  switch(IN_State) {   // Transitions
     case IN_Init:  // Initial transition
	PORTC = 0x07;
        IN_State = IN_Start;
        break;

     case IN_Start:
	if ((PINA & 0x01) == 0x01)
	{
		IN_State = IN_Increment;
        	if ((PORTC & 0x0F) != 0x09) 
           		PORTC = PORTC + 1;
		else
			PORTC = PORTC;
	}
        if ((PINA & 0x02) == 0x02) 
	{
		IN_State = IN_Decrement;
		if (PORTC != 0x00)
                        PORTC = PORTC - 1;
                else
                        PORTC = PORTC;
        }
	if ((PINA & 0x03) == 0x03)
		IN_State = IN_Reset;
        break;

     case IN_Increment:
        if ((PINA & 0x01) == 0x01)
        {
                IN_State = IN_Increment;
                if ((PORTC & 0x0F) != 0x09)
                        PORTC = PORTC + 1;
                else
                        PORTC = PORTC;
        }
        if ((PINA & 0x02) == 0x02)
        {
                IN_State = IN_Decrement;
                if (PORTC != 0x00)
                        PORTC = PORTC - 1;
                else
                        PORTC = PORTC;
        }
        if ((PINA & 0x03) == 0x03)
                IN_State = IN_Reset;
	break;

	case IN_Decrement:
	if ((PINA & 0x01) == 0x01)
        {
                IN_State = IN_Increment;
                if ((PORTC & 0x0F) != 0x09)
                        PORTC = PORTC + 1;
                else
                        PORTC = PORTC;
        }
        if ((PINA & 0x02) == 0x02)
        {
                IN_State = IN_Decrement;
                if (PORTC != 0x00)
                        PORTC = PORTC - 1;
                else
                        PORTC = PORTC;
        }
        if ((PINA & 0x03) == 0x03)
                IN_State = IN_Reset;
	break;

	case IN_Reset:
	IN_State = IN_Start;

     default:
        IN_State = IN_Start;
        break;
  } // Transitions

  switch(IN_State) {   // State actions
     case IN_Init:
        break;

     case IN_Start:
	break;

     case IN_Increment:
        break;

     case IN_Decrement:
	break;

     case IN_Reset:
	PORTC = 0x00;
	break;

     default:
        break;
   } // State actions
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	PORTC = 0x00;
	IN_State = IN_Init;

    while (1) {
	TickFct_In();
    }
return 0;
}
