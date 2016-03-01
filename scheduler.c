#include <msp430.h>
#include "ports.h"
#include <stdio.h>
#include "scheduler.h"
#include "blink.h"

static int elapsed_ticks = 0;

void Enable_Interrupts(void){
  __enable_interrupt();
}

void Disable_Interrupts(void){
  __disable_interrupt(); 
}

task_type tasks[NUM_TASKS];

void Create_Task(void (*function_pointer)(void),
                 int period,
                 int delay) {
  static int index = 0;

  tasks[index].task = function_pointer;
  tasks[index].period = period;
  // Avoid underflow in the dispatcher.
  tasks[index].delay = delay + 1;
  ++index;
}

void Timer_ISR(void)
{
  ++elapsed_ticks; //Increases ticks to 1, this makes the dispatch loop run.
}


void Dispatch_Tasks(void)
{
  Disable_Interrupts();
  while (elapsed_ticks > 0) { // TRUE only if the ISR ran.
    for (int i = 0; i < NUM_TASKS; i++) {
      if (--tasks[i].delay == 0) {
        tasks[i].delay = tasks[i].period;

        Enable_Interrupts();
        tasks[i].task(); // Execute the task!
        Disable_Interrupts();
      }
    }
    --elapsed_ticks;
  }
  Enable_Interrupts();
}

void Create_tasks(void){

  Create_Task(blink,5,5);

}
