#include <stdio.h>
#include "split.h"

static int prefix[MAXN], top;
static int target;

void PRINT(){
    int i;
    printf("%d = %d", target, prefix[0]);
    for(i = 1;i < top; ++ i){
        printf("+%d", prefix[i]);
    }
    printf("\n");
    return;
}

void dfs(int rest, int lim, int dep){
    if(rest == 0){
        top = dep;
        if(dep != 1) PRINT();
        return;
    }
    lim = lim < rest ? lim : rest;
    int i;
    for(i = lim;i > 0;--i){
        prefix[dep] = i;
        dfs(rest-i, i, dep+1);
    }
}

void splitNum(int num){
    target = num;
    dfs(num, num, 0);
}