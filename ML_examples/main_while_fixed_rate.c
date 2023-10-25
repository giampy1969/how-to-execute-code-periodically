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
  
  unsigned int T=100, Tf=10000;
  DWORD t_start, t_task, t_loop;
  
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  algorithm_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  t_loop = GetTickCount();
  while (GetTickCount()-t_loop < Tf) {
      
      /* get start time, execute algorithm and calculate task time */
      t_start = GetTickCount();
      main_algorithm();
      t_task = GetTickCount() - t_start;
      
      /* sleep for the rest of the period */
      Sleep(T-t_task);

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
