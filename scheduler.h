#include <msp430.h>
#include <stdio.h>

typedef struct {
  void   (*task)(void); // Pointer to the task function.
  int period;      // Period to execute with.
  int delay;       // Delay before first call.
} task_type;


void Enable_Interrupts(void);
void Disable_Interrupts(void);

void Create_Task(void (*function_pointer)(void),
                 int period,
                 int delay);
void Timer_ISR(void);
void Dispatch_Tasks(void);
void Create_tasks(void);

