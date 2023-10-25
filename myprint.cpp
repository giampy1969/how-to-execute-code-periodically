#include "myprint.h"

extern "C" void myprint_init(double par1, double par2) {   
    printf("Init: Par1= %f \n", par1);
    printf("Init: Par2= %f \n", par2);
}

extern "C" void myprint_output(double val) {
    printf("Step: Output: %f \n", val);
}

// [EOF]

