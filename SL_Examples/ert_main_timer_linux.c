/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'algorithm_sl'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Mar  7 15:27:04 2017
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

#include <sys/time.h>   /* for setitimer */
#include <unistd.h>     /* for pause */
#include <signal.h>     /* for signal */

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
    
    /* Re-set the handler to rt_OneStep, just in case  */
    signal(SIGALRM, rt_OneStep);
    
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

  /* Define the timer structure */
  struct itimerval it_val;
  
  /* Initialize model */
  algorithm_sl_initialize();
  
  /* Upon SIGALRM, call main_algorithm() */
  if (signal(SIGALRM, (void(*)(int)) rt_OneStep) == SIG_ERR) {
      perror("Unable to catch SIGALRM");
      exit(1);
  }
  
  /* Define Sampling time in secs and microsecs */
  it_val.it_value.tv_sec =     0;
  it_val.it_value.tv_usec =    100000;
  it_val.it_interval = it_val.it_value;
  
  /* Set the timer */
  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
      perror("error calling setitimer()");
      exit(1);
  }
  
  while (1) {
      pause();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  algorithm_sl_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
