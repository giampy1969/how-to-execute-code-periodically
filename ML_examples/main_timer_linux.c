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

#include <sys/time.h>	/* for setitimer */
#include <unistd.h>		/* for pause */
#include <signal.h>		/* for signal */

/* Function Declarations */
static void main_algorithm(void);

/* Function Definitions */

static void main_algorithm(void)
{
    /* Call the entry-point 'algorithm'. */
    algorithm();
    signal(SIGALRM, main_algorithm);
}

int main(int argc, const char * const argv[])
{
    
    /* Define the timer structure */
    struct itimerval it_val;
    
    (void)argc;
    (void)argv;
    
    /* Initialize the application.
     You do not need to do this more than one time. */
    algorithm_initialize();
    
    /* Upon SIGALRM, call main_algorithm() */
    if (signal(SIGALRM, (void(*)(int)) main_algorithm) == SIG_ERR) {
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
    
	/* Do whatever */
	while(1) {
        pause();
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
