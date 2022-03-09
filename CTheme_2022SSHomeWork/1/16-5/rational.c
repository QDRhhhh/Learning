#include "rational.h"

ll gcd(ll x, ll y){
    return y ? gcd(y, x%y) : x;
}

void simplify(struct RationalT * x){
    
    if(x->den == 0){
        printf("[FATIL] # div/0\n");
        freeAll();
        exit(0);
    }

    ll tmp = gcd(x->den, x->num);
    x->den /= tmp, x->num /= tmp;
    return;
}

struct RationalT * CreateRational(int num, int den){
    struct RationalT * newT = (struct RationalT *)malloc(sizeof(struct RationalT));
    newT->num = num, newT->den = den;
    simplify(newT);
    pointerList[ RT_top++ ] = newT;
    return newT;
}

struct RationalT * AddRational(struct RationalT * r1, struct RationalT * r2){
    struct RationalT * tmp = (struct RationalT *)malloc(sizeof(struct RationalT));
    tmp->den = r1->den * r2->den;
    tmp->num = r1->den * r2->num + r1->num * r2->den;
    simplify(tmp);
    pointerList[ RT_top++ ] = tmp;
    return tmp;
}

struct RationalT * MultiplyRational(struct RationalT * r1, struct RationalT * r2){
    struct RationalT * tmp = (struct RationalT *)malloc(sizeof(struct RationalT));
    tmp->den = r1->den * r2->den;
    tmp->num = r1->num * r2->num;
    simplify(tmp);
    pointerList[ RT_top++ ] = tmp;
    return tmp;
}

void GetRational(struct RationalT * r){
    ll x, y;
    scanf("%lld/%lld", &x, &y);
    r->num = x, r->den = y;
    simplify(r);
    return;
}

double RToD(struct RationalT * t){
    return (double)(t->num) / (double)(t->den);
}

void PrintRational(struct RationalT * r, char end){
    printf("%lld/%lld = %lf", r->num, r->den, RToD(r));
    printf("%c", end);
}

void freeAll(){
    int i;
    for(i = 0;i < RT_top;++i){
        free( pointerList[i] );
    }
}
