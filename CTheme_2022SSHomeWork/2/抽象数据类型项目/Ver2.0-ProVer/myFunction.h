#ifndef __MYFUNCTION__
#define __MYFUNCTION__

#define MAXNF 1024

#include <stdio.h>
#include <math.h>
#include <string.h>

static int alreadyInit = 0;

typedef struct MyFunction{
    // TODO: Do something to adapt more arguments.
    // C don't have default arguments. (Really?)
    // See https://stackoverflow.com/questions/1472138/c-default-arguments
    double (* option)(double x);
    char * name;
    // TODO: Add a variable to identify the number of the arguments of the function.
} MyFun;

static int Ftop = 0;
static MyFun Flist[MAXNF];

// this function is visible because I use '^' to call it.
double _pow(double x,double p);

// register all the function so that you can get them
void initMyFunc();

// judge whether the function is registerred
int isFuncExist(char * expr);

// call the function with fid and argument argv
double useFuncById(int fid, double argv); 

#endif