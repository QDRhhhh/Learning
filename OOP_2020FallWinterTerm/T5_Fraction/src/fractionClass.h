#ifndef __Fraction_Class__
#define __Fraction_Class__

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Fractions{
private:
    long long numerator , denominator;
    int sgn;
public:
    Fractions();
    Fractions(long long, long long);
    Fractions(const Fractions&);
    Fractions(string);
    ~Fractions();

    long long calGcd(long long,long long);
    void symplify();
    double toDouble() const;
    string toString() const;
    
    const Fractions operator + (Fractions &);
    const Fractions operator - (Fractions &);
    const Fractions operator * (Fractions &);
    const Fractions operator / (Fractions &);

    bool operator < (Fractions &);
    bool operator <= (Fractions &);
    bool operator > (Fractions &);
    bool operator >= (Fractions &);
    bool operator == (Fractions &);
    bool operator != (Fractions &);

    friend istream &operator>>(istream & is,Fractions &rhs);
    friend ostream &operator<<(ostream & os,const Fractions &rhs);
};


#endif