/*	Author: lab
 *  Partner(s) Name: Alex Castillo
 *	Lab Section: 23
 *	Assignment: Lab #4  Exercise #4
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

enum LO_States { LO_Start,LO_X1,LO_Y1,LO_Hash1,LO_XX,LO_XY,LO_XHash,LO_YX,
		 LO_YY,LO_YHash,LO_HashX,LO_HashY,LO_HashHash,LO_Lock1,LO_Lock2} LO_State;

void TickFct_Lo()
{
  switch(LO_State) {   // Transitions
     case LO_Start:  // Initial transition
        if ((PINA | 0xF0) == 0xF0)
		LO_State = LO_X1;
	if ((PINA & 0x01) == 0x01)
		LO_State = LO_Y1;
	if ((PINA & 0x02) == 0x02)
		LO_State = LO_Hash1;
        break;

     case LO_X1:
        if ((PINA | 0xF0) == 0xF0)
                LO_State = LO_XX;
        if ((PINA & 0x01) == 0x01)
                LO_State = LO_XY;
        if ((PINA & 0x02) == 0x02)
                LO_State = LO_XHash;
	break;

     case LO_Y1:
	if ((PINA | 0xF0) == 0xF0)
                LO_State = LO_YX;
        if ((PINA & 0x01) == 0x01)
                LO_State = LO_YY;
        if ((PINA & 0x02) == 0x02)
                LO_State = LO_YHash;
	break;

     case LO_Hash1:
	if ((PINA | 0xF0) == 0xF0)
                LO_State = LO_HashX;
        if ((PINA & 0x01) == 0x01)
                LO_State = LO_HashY;
        if ((PINA & 0x02) == 0x02)
                LO_State = LO_HashHash;
        break;
     case LO_XX:
	LO_State = LO_Start;
	break;
     case LO_XY:
	LO_State = LO_Start;
        break;
     case LO_XHash:
	LO_State = LO_Start;
        break;
     case LO_YX:
	LO_State = LO_Start;
        break;
     case LO_YY:
	LO_State = LO_Start;
        break;
     case LO_YHash:
	LO_State = LO_Start;
        break;
     case LO_HashX:
	LO_State = LO_Start;
        break;
     case LO_HashY:
	if((PINA & 0x02) == 0x02)
		LO_State = LO_Lock1;
	else
		LO_State = LO_HashY;
	break;
     case LO_HashHash:
	LO_State = LO_Start;
	break;
     case LO_Lock1:
	if((PINA & 0x01) == 0x01)
		LO_State = LO_Lock2;
	else
		LO_State = LO_HashY;
	break;
     case LO_Lock2:
	LO_State = LO_Start;
	break;
     default:
	LO_State = LO_Start;
	break;


  } // Transitions

  switch(LO_State) {   // State actions
     case LO_Start:
	PORTB = 0x00;
	PORTC = 0x00;
        break;

     case LO_X1:
	PORTC = 0x01;
        break;

     case LO_Y1:
	PORTC = 0x02;
        break;

     case LO_Hash1:
	PORTC = 0x03;
        break;
     case LO_XX:
	PORTC = 0x04;
        break;
     case LO_XY:
	PORTC = 0x05;
        break;
     case LO_XHash:
	PORTC = 0x06;
        break;
     case LO_YX:
	PORTC = 0x07;
        break;
     case LO_YY:
	PORTC = 0x08;
        break;
     case LO_YHash:
	PORTC = 0x09;
        break;
     case LO_HashX:
	PORTC = 0x0A;
        break;
     case LO_HashY:
        PORTB = 0x01;
	PORTC = 0x0B;
	break;
     case LO_HashHash:
	PORTC = 0x0C;
	break;
     case LO_Lock1:
	PORTB = 0x01;
	PORTC = 0x0D;
	break;
     case LO_Lock2:
	PORTB = 0x00;
	PORTC = 0x0E;
	break;
     default:
        break;
   } // State actions
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	PORTB = 0x00;
	PORTC = 0x00;
	LO_State = LO_Start;

    while (1) {
	TickFct_Lo();
    }
return 0;
}
