#ifndef __RATIONAL__
#define __RATIONAL__

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

struct RationalT{
    ll num, den;
};

// limit the maximun of rationalT pointers
// const int RT_MAX = 1024;
static struct RationalT * pointerList[ 1024 ];
static int RT_top = 0;

// calculate the gcd of x and y
ll gcd(ll x, ll y);

// simplify a rotional number
void simplify(struct RationalT * x);

// create a new rational number 
struct RationalT * CreateRational(int num, int den);

// plus rational number r1 and rational number r2
struct RationalT * AddRational(struct RationalT * r1, struct RationalT * r2);

// multiply rational number r1 and rational number r2
struct RationalT * MultiplyRational(struct RationalT * r1, struct RationalT * r2);

// read in a rational number in the form of "<num>/<den>" and write it into r
// eg : you can enter "3/5" to input \frac{3}{5}
void GetRational(struct RationalT * r);

// change the rational number into decimal form
double RToD(struct RationalT * t);

// print the number in decimal form
void PrintRational(struct RationalT * r, char end);

// free all pointers of RationalT
void freeAll();

#endif