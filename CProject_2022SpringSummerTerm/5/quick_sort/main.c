#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e6+9;

#include "myAlgorithm.h"

void solve(){
    int i, n, mode = 1;
    double a[1000010];
    printf("If you want the array to be ascending, than just enter the length of the array.\n");
    printf("Otherwise, enter the opposite number of the length.\n");
    printf("The absolute value of it shouldn't be lager than 1024\n");
    scanf("%d", &n);
    if(n < 0) mode = 0, n = -n;
    printf("Then enter the elements of the array one by one, intervaled with a 'space'.\n");
    for(i = 0;i < n;++i) scanf("%lf", &a[i]);
    myQuickSort(a, a+n, mode);
    for(i = 0;i < n;++i) printf("%lf ", a[i]);
}

int main(){
    int _ = 1;
    // scanf("%d",&_);
    while(_--) solve();
}
