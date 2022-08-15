#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e6+9;

#include "rational.h"

void solve(){
    struct RationalT * r1 = CreateRational(1,1), * r2 = CreateRational(1,1);
    GetRational(r1), GetRational(r2);
    struct RationalT * r3 = CreateRational(114514, 1919810);
    struct RationalT * sum = AddRational(r1, r2);
    struct RationalT * pro = MultiplyRational(r1, r2);
    PrintRational(r1, ' ');
    PrintRational(r2, ' ');
    PrintRational(r3, '\n');
    PrintRational(sum, '\n');
    PrintRational(pro, '\n');

    // safe test
    // it will exit with 0 and log "[FATAL] # div 0"
    struct RationalT * r4 = CreateRational(0, 0);
    PrintRational(r4, '\n');
    
    // will never run
    freeAll();
}

int main(){
    int _ = 1;
    // scanf("%d",&_);
    while(_--) solve();
}
