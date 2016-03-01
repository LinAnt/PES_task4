//Ports.h - specifys wich ports are to be used!
#define LED1 BIT0
#define LED2 BIT6

#define S1 BIT3

#define DCO_FREQ 1*1e6
#define TIMER_INTERVAL 100 //given in ms

#define DIVIDER 8
#define TMRC (DCO_FREQ / DIVIDER / 1000 * TIMER_INTERVAL)

#define NUM_TASKS 1 //Decides how big the task array should be.
