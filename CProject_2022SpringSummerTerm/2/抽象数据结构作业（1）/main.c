#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e6+9;

int _;

#include "queue.h"

void solve(char MOD){
    int supI, supP;
    if(MOD == 'n'){
        supI = supP = 16;
    } else if(MOD == 'i'){
        supI = 17, supP = 16;
    } else if(MOD == 'p'){
        supI = 16, supP = 17;
    } else {
        Panic("Invalid option.");
    }

    MyQ * q = NewQueue();
    int a[1024];
    for(_ = 0;_ < 1024;++_){
        a[_] = _;
    }
    for(_ = 0;_ < supI;_ += 1){
        Enqueue(q,&a[_]);
    }   
    for(_ = 0;_ < supP;_ += 4){
        int * p = Dequeue(q);
        printf("a[%d] = %d\n", _, *p);
    }
    FreeAll();
}

int main(int argc,char *argv[]){
    if(argc == 1){
        printf("Please read \' Readme.md \' first!\n");
    } else {
        if(argc == 3 && *argv[2] == 'l')
            setPrintLog(1);
        else
            setPrintLog(0);
        solve(*argv[1]);
    }
}
