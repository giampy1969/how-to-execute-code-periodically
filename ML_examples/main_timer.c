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
  
  /* Define sampling time and timer handle */
  unsigned int T=100;
  HANDLE hTimer = NULL;
  
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  algorithm_initialize();

  /* Set a timer to call the timer routine every T ms */
  if (!CreateTimerQueueTimer( &hTimer, NULL,
          (WAITORTIMERCALLBACK)main_algorithm, NULL , 0, T, 0)) {
      printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
      return 3;
  }
  
  while (1) {
      Sleep(1000*T); /* Sleep to avoid 100% CPU utilization */
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
