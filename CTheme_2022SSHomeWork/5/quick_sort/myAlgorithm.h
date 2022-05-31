#ifndef __My_Algorithm__
#define __My_Algorithm__

#include <stdio.h>

// It shouln't be less than log(len).
#define MAXN 10240

// Print logs or not.
#define doLog 0

// A stack to store the option.
struct MethodStack{
    double * l, * r;
};

// The quic sort function that sort the array.
// Let <begin> be the first address of the array and <end>
// be the address after the last elements' address.
// Set <mode>  1 if you want an ascending array,
// if not, set it  0.
// || For example, if you want such an array to be descending:
// || a[13] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
// || Then call: 
// || myQuickSort(a, a+13, 0);
void myQuickSort(double * begin, double * end, int mode);

#endif
