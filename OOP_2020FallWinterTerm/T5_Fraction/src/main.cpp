#include <iostream>
#include <iomanip>
#include "fractionClass.h"

int main(){
    Fractions a,b;
    cin >> a >> b;
    Fractions c = b;
    Fractions d(-4,8);
    cout << setiosflags(ios::left);
    cout << setw(8) << a << " " << setw(8) << b << " " << setw(8) << c << " " << setw(8) << d << endl;
    cout << setw(8) << a.toDouble() << " " << setw(8) << b.toDouble() << " " << setw(8) << c.toDouble() << " " << setw(8) << d.toDouble() << endl;
    cout << setw(8) << a << setw(4) << "+" << setw(8) << b << setw(4) << "=" << setw(8) << a+b << endl;
    cout << setw(8) << a << setw(4) << "-" << setw(8) << b << setw(4) << "=" << setw(8) << a-b << endl;
    cout << setw(8) << a << setw(4) << "*" << setw(8) << b << setw(4) << "=" << setw(8) << a*b << endl;
    cout << setw(8) << a << setw(4) << "/" << setw(8) << b << setw(4) << "=" << setw(8) << a/b << endl;

    cout << setw(8) << a << setw(4) << ">" << setw(8) << b << setw(4) << "=" << setw(8) << (a>b) << endl;
    cout << setw(8) << a << setw(4) << ">=" << setw(8) << b << setw(4) << "=" << setw(8) << (a>=b) << endl;
    cout << setw(8) << a << setw(4) << "<" << setw(8) << b << setw(4) << "=" << setw(8) << (a<b) << endl;
    cout << setw(8) << a << setw(4) << "<=" << setw(8) << b << setw(4) << "=" << setw(8) << (a<=b) << endl;
    cout << setw(8) << b << setw(4) << "==" << setw(8) << c << setw(4) << "=" << setw(8) << (b==c) << endl;
    cout << setw(8) << b << setw(4) << "!=" << setw(8) << c << setw(4) << "=" << setw(8) << (b!=c) << endl;

}