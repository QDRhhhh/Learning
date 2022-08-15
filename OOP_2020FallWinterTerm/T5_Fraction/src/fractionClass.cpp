#include "fractionClass.h"

Fractions::Fractions(){
    numerator = 0;
    denominator = 0;
}

Fractions::Fractions(long long x, long long y){
    if(x < 0){
        x *= -1;
        sgn = -1;
    } else {
        sgn = 1;
    }
    numerator = x;
    denominator = y;
    symplify();
}

Fractions::Fractions(const Fractions &rhs){
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;
    this->sgn = rhs.sgn;
    this->symplify();
}
    
Fractions::Fractions(string num){
    long long realNumerator = 0;
    long long realDenominator = 1;
    long long realZ = 0;
    int n = num.length();
    bool pointFlag = false;

    // TODO: Check whether num is a logical float number.

    for(int i = 0;i < n;++i){
        if(num[i] == '-' && i == 0){
            sgn = -1;
        } else if(i == 0){
            sgn = 1;
        }

        if(num[i] == '.'){
            pointFlag = true;
            continue;
        } else if(pointFlag){
            realDenominator *= 10;
            realNumerator = realNumerator * 10 + num[i] - '0';
        } else {
            realZ = realZ * 10 + num[i] - '0';
        }
    }
    numerator = realNumerator + realZ * realDenominator;
    denominator = realDenominator;
    symplify();
}
Fractions::~Fractions(){

}

long long Fractions::calGcd(long long x,long long y){
    return y == 0 ? x : calGcd(y,x%y);
}
void Fractions::symplify(){
    if(denominator == 0) return;

    long long GCD = calGcd(numerator,denominator);
    numerator /= GCD;
    denominator /= GCD;
}
double Fractions::toDouble() const {
    if(denominator == 0){
        return 0;
    } else {
        return (double)sgn * (double)numerator/(double)denominator;
    }
}
string Fractions::toString() const {
    string res("");
    if(denominator == 0){
        return res.append("ERROR#Div0");
    } 

    ostringstream osN,osD;
    osN.clear() , osD.clear();
    osN << numerator;
    osD << denominator;
    string sNu(osN.str());
    string sDe(osD.str());    

    if(sgn == -1){
        res.append("-");
    }

    if(sDe == "1"){
        return res.append(sNu);
    } else {
        res.append(sNu);
        res.append("/");
        res.append(sDe);
        return res;
    }
}
    
const Fractions Fractions::operator + (Fractions &rhs){
    Fractions res(
        this->sgn * this->numerator * rhs.denominator +  rhs.sgn * this->denominator * rhs.numerator ,
        this->denominator * rhs.denominator
    );
    res.symplify();
    return res;
}
const Fractions Fractions::operator - (Fractions &rhs){
    Fractions res(
        this->sgn * this->numerator * rhs.denominator - rhs.sgn * this->denominator * rhs.numerator,
        this->denominator * rhs.denominator
    );
    symplify();
    return res;
}
const Fractions Fractions::operator * (Fractions &rhs){
    Fractions res(
        this->numerator * rhs.numerator ,
        this->denominator * rhs.denominator
    );
    symplify();
    return res;
}
const Fractions Fractions::operator / (Fractions &rhs){
    Fractions res(
        this->numerator * rhs.denominator ,
        this->denominator * rhs.numerator
    );
    symplify();
    return *this;
}

bool Fractions::operator < (Fractions &rhs){
    if(this->sgn != rhs.sgn){
        return this->sgn < rhs.sgn;
    } else {
        if(this->sgn == 1){
            return this->numerator * rhs.denominator < rhs.numerator * this->denominator;
        } else {
            return this->numerator * rhs.denominator > rhs.numerator * this->denominator;
        }
    }
}
bool Fractions::operator <= (Fractions &rhs){
    return !(*this > rhs);
}
bool Fractions::operator > (Fractions &rhs){
    return rhs < *this;
}
bool Fractions::operator >= (Fractions &rhs){
    return !(*this < rhs);
}
bool Fractions::operator == (Fractions &rhs){
    return (rhs <= *this) && (rhs >= *this);
}
bool Fractions::operator != (Fractions &rhs){
    return !(rhs == *this);
}

istream &operator>>(istream & is,Fractions &rhs){
    char op;
    is >> rhs.numerator >> op >> rhs.denominator;
    if(rhs.numerator < 0){
        rhs.numerator *= -1;
        rhs.sgn = -1;
    } else {
        rhs.sgn = 1;
    }
    rhs.symplify();
    return is;
}
ostream &operator<<(ostream & os,const Fractions &rhs){
    return os << rhs.toString();
}