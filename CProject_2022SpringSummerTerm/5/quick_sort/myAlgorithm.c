#include "myAlgorithm.h"

// swap the value of the two arguments.
void swap(double * x, double * y){
    double tmp = *x;
    *x = *y;
    *y = tmp;
}

// Less equal comparation function.
int leq(double x, double y, int mode){
    if(mode) return x <= y;
    else return x >= y;
}

// The quic sort function that sort the array.
// Let <begin> be the first address of the array and <end>
// be the address after the last elements' address.
// Set <mode>  1 if you want an ascending array,
// if not, set it  0.
// || For example, if you want such an array to be descending:
// || a[13] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
// || Then call: 
// || myQuickSort(a, a+13, 0);
void myQuickSort(double * begin, double * end, int mode){
    struct MethodStack opt[MAXN];
    int top = 0;
    opt[top].l = begin, opt[top].r = end;
    ++top;
    while(top){
        --top;
        double * l = opt[top].l, * r = opt[top].r;

        // Log
        if(doLog) printf("%lf %lf\n", *l, *(r-1));

        if(r-l <= 1) continue;
        double * ll = l, * rr = r;
        double * base = l;
        ++l, --r;
        while(l < r){
            
            // Log
            if(doLog) printf(" %lf %lf\n", *l, *r);

            while( leq(*base, *r, mode) && l < r ) --r;
            while( leq(*l, *base, mode) && l < r ) ++l;
            swap(l, r);
        }

        // Log
        // printf("mid: %lf\n", *l);

        if( !leq(*base, *r, mode) ){
            if(doLog) printf("[1]\n");
            swap(base, r);
            opt[top].l = ll, opt[top].r = l, ++top;
            opt[top].l = l+1, opt[top].r = rr, ++top;
        } else {
            if(doLog) printf("[2]\n");
            opt[top].l = ll+1, opt[top].r = rr, ++top; 
        }
    }

    
}

