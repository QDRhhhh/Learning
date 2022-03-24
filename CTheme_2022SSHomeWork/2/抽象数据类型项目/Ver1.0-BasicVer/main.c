#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e6+9;

#include "calculator.h"

void solve(){
    char expr[MAXNS];
    printf("Please enter a valid expression:\n");

    scanf("%s", expr);

    Stack * RPE = toReversePolishExpression(expr);    
    int ans = dealReversePolishExpression(RPE);

    printf("%d", ans);
    free(RPE);
}

int main(int argc,char *argv[]){
    if(argc == 2 && *argv[1] == 'l') setLogStates(1);
    else setLogStates(0);
    solve();
}