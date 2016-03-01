#include <msp430.h>
#include "ports.h"
#include <stdio.h>

void setup(void){
  WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer // See function above
	P1DIR |= (LED1 | LED2);   	//Set LEDs to output direction

	BCSCTL1 = CALBC1_1MHZ;  //set DCO to 1Mhz
	DCOCTL = CALDCO_1MHZ;

	//Set up interrupts and timer 0

	CCTL0 = CCIE;
	TACTL = TASSEL_2 + MC_1 + ID_3;

	CCR0 = TMRC; //TMRC is defined in ports.h

  P1DIR &= ~S1;   // Set button pin as an input pin
  P1OUT |= S1;    // Set pull up resistor on for button
  P1REN |= S1;    // Enable pull up resistor for button to keep pin high until pressed
  __enable_interrupt();
  _BIS_SR(LPM1_bits + GIE); // Enter LPM1
}

