#include <stdio.h>
#include "split.h"

int main(){
    int n;
    printf("Please enter the target number to be split : \n");
    scanf("%d", &n);
    splitNum(n);
    return 0;
}