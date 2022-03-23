#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e6+9;

#include "linkedlist.h"

void solve(){
    MyLL S1, S2, S3;
    S1.head = S1.tail = NULL;
    S2.head = S2.tail = NULL;
    S3.head = S3.tail = NULL;
    while(1){
        int x;
        scanf("%d",&x);
        if(x == -1) break;
        InsertElement(&S1, x);
    }
    while(1){
        int x;
        scanf("%d",&x);
        if(x == -1) break;
        InsertElement(&S2, x);
    }
    // PrintElements(&S1);
    // PrintElements(&S2);
    Merge(&S3,&S1,&S2);
    PrintElements(&S3);
}

int main(){
    int _ = 1;
    // scanf("%d",&_);
    while(_--) solve();
}
