#include "myFunction.h"

double _pow(double x,double p){ return pow(x,p); }

double _sqrt(double x){ return sqrt(x); }

double _sin(double x){ return sin(x); }

double _cos(double x){ return cos(x); }

double _tan(double x){ return _sin(x)/_cos(x); }

// add your function here ↓
double _yourFunc(double x){ return x*2; }

// register all the function so that you can get them
void initMyFunc(){
    if(alreadyInit) return;
    alreadyInit = 1;
    Ftop = 0;
    
    // use function pointer to make the relationships
    Flist[ Ftop ].name = "sin", Flist[ Ftop++ ].option = _sin;
    Flist[ Ftop ].name = "cos", Flist[ Ftop++ ].option = _cos;
    Flist[ Ftop ].name = "tan", Flist[ Ftop++ ].option = _tan;
    Flist[ Ftop ].name = "sqrt", Flist[ Ftop++ ].option = _sqrt;

    // register your function here like this ↓
    Flist[ Ftop ].name = "YourFuncName", Flist[ Ftop++ ].option = _yourFunc;
}

// judge whether the function is registerred
int isFuncExist(char * expr){
    int i = 0;
    //TODO: Order Maintenance & Binary Search to improve efficiency (no need)
    for(;i < Ftop;++i){
        if( !strcmp(Flist[i].name, expr) ) return i;
    }
    // will return -1 if not exist
    return -1;
}

// call the function identified by fid and argument argv
double useFuncById(int fid, double argv){ return Flist[fid].option(argv); }