/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'algorithm_sl'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Mon Mar 06 17:44:52 2017
 * Copyright 2017, The MathWorks, Inc 
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "algorithm_sl.h"              /* Model's header file */
#include "rtwtypes.h"

#include <windows.h> /* Using Sleep, GetTickCount, or Timers */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(algorithm_sl_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  algorithm_sl_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  unsigned int T=100, Tf=10000;
  DWORD t_start, t_task, t_loop;
  
  /* Initialize model */
  algorithm_sl_initialize();
  
  t_loop = GetTickCount();
  t_start = GetTickCount();
  while (GetTickCount()-t_loop < Tf) {
      
      if (GetTickCount()-t_start>=T) {
          
          /* get t_start, execute algorithm and calculate task time */
          t_start = GetTickCount();
          rt_OneStep();
          t_task = GetTickCount() - t_start;
          
          /* sleep until 5 ms before the start of the next period */
          /* removing this line will cause 100% CPU utilization */
          Sleep(T-t_task-5);
      }
      
  }

  /* Terminate model */
  algorithm_sl_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
