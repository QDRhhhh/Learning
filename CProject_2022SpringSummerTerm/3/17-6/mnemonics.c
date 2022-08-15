#include <stdio.h>
#include <string.h>
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3F3F3F3F;
const int N = 1e5+9;

char dic[10][3];
char output[100024];

void init(){
    int i, j;
    char ch = 'A';
    for(i = 2;i <= 9;++i){
        for(j = 0;j < 3;++j){
            if(ch == 'Q') ++ch;
            dic[i][j] = ch++;
        }
    }
    for(i = 0;i < N;++i) output[i] = 0;
}

void dfs(int *a, int dep){
    if(dep == a[0]){
        printf("%s\n", output);
        return;
    }
    if(a[ dep+1 ] < 2){
        output[dep] = '0' + a[ dep+1 ];
        dfs(a, dep+1);
    } else {
        int i;
        for(i = 0;i < 3;++i){
            output[dep] = dic[ a[ dep+1 ] ][i];
            dfs(a, dep+1);
        }
    }
    return;
}

int main(){
    int i, j;
    char str[100024];
    int num[100024];
    init();
    printf("Please enter the number : \n");
    scanf("%s", str);
    num[0] = strlen(str);
    for(i = 1;i <= num[0];++i){
        num[i] = str[i-1] - '0';
    }
    dfs(num, 0);
}
