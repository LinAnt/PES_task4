#include <msp430.h>
#include "ports.h"

void blink(void){

  P1OUT ^= (LED1 | LED2);

};


