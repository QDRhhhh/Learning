#ifndef __MYFUNCTION__
#define __MYFUNCTION__

#define MAXNF 1024

#include <stdio.h>
#include <math.h>
#include <string.h>

static int alreadyInit = 0;

// only argc = 1 
typedef struct MyFunction{
    double (* option)(double x);
    char * name;
} MyFun;

static int Ftop = 0;
static MyFun Flist[MAXNF];

double _pow(double x,double p);

// register all the function so that you can get them
void initMyFunc();

// judge whether the function is registerred
int isFuncExist(char * expr);

// call the function with fid and argument argv
double useFuncById(int fid, double argv); 

#endif