/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 04-Mar-2017 15:31:19
 * Copyright 2017, The MathWorks, Inc 
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "algorithm.h"
#include "main.h"
#include "algorithm_terminate.h"
#include "algorithm_initialize.h"

#include <windows.h>    /* Using Sleep, GetTickCount, or Timers */

/* Function Declarations */
static void main_algorithm(void);

/* Function Definitions */

static void main_algorithm(void)
{
  /* Call the entry-point 'algorithm'. */
  algorithm();
}

int main(int argc, const char * const argv[])
{
  
  unsigned int i, T=100;
  
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  algorithm_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  for (i=0;i<101;i++) {
      main_algorithm();
      Sleep(T);
  }
  
  /* Terminate the application.
     You do not need to do this more than one time. */
  algorithm_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
