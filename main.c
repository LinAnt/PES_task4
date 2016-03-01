#include <msp430.h>
#include "ports.h"
#include <stdio.h>
#include "scheduler.h"
#include "setup.h"


//This starts the timer interrupts for the Timer_ISR. This will increment the elapsed_ticks variable and trigger the dispathcer.
__attribute__((interrupt(TIMER0_A0_VECTOR))) void Timer_A(void) {
  Timer_ISR();
}

int main(void){
  setup();
  Create_tasks();
  P1OUT &= LED1;
  P1OUT &= LED2;


  while(1);
  for(;;) {
    volatile unsigned int i;    //volatile to prevent optimization
    Dispatch_Tasks();
  }
  return 0;
}
