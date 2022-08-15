#include "utils.h"

// Be used to calculate the mininum of x(double) 
// and y(double).
double min(double x, double y){
    return x < y ? x : y;
}

// Be used to change the angle to radian.
double AtoR(double a){
    return a / 180 * 3.1415926;
}