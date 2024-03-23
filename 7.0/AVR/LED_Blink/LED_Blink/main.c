/*LED_Blink.c
* Created: 12/03/2023 13:59:36
* For Arduino Pro Mini with ATmega328P
* Fuses: E=0xFD, H=0xDA & L=0xFF
* Device signature = 0x1E950F
*/

#ifndef F_CPU
#define F_CPU 16000000UL // Specify actual clock speed of target CPU so any delay macros have accurate timings.  Here 16 MHz clock speed. To verify crystal frequency set delay to 1s and count 30 LED flash cycles per minute
#endif

#include <avr/io.h> //I/O definitions including the particular device we use e.g ATmega328P, which is specified in PROJECT > "Project Name" > Device
#include <util/delay.h> //Convenience functions for busy-wait delay loops
#include <avr/cpufunc.h> //This header file contains macros (e.g. _NOP(); that access special functions of the AVR CPU which do not fit into any of the other header files.

int main(void)
{
	DDRB = DDRB | 0b00000010; //PORTB1 to an output, known as Digital pin D9 on an Arduino Pro Mini, drives Yellow LED on AVR Dragon programmer board
	
	while(1) //infinite loop
	{
		PORTB ^= 1 << PINB1; //Toggle Pin B1 on Port B, known as Digital Pin 9 on an Arduino Pro Mini.  Can't use on-board LED as connected to PB5 which is used as SCK form the connection to the AVR Dragon programmer
		_NOP();
		_delay_ms(50);
		_NOP();
	}
	
}




