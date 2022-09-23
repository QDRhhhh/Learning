#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include "helper/CNewbieHelper.h"
#include "matrix_utils.h"
#include "N3.h"
#include "N4.h"
#include "N6.h"

// Do one round.
double foo(int round){
    Matrix matrixObj, *mat = &matrixObj;
    M_INIT(mat);

    clock_t timerI = clock();
    int ans = calMaxSubMatrixSum(mat);
    clock_t timerF = clock();
    double delTime = (double)(timerF-timerI)/CLOCKS_PER_SEC;

    printf("%d\n", ans);
    // printf("Program Finished in %.4lf seconds!", (double)(timerF-timerI)/CLK_TCK);
    
    FILE * fp = fopen("output_details.txt", "a");
    fprintf(fp, "Method: N%d,  Size: %d*%d,  Round: %d\n  The ans is: %d \n  The delta time is: %.6lf\n", getMethod(),  mat->n, mat->m, round, ans, delTime);
    fclose(fp);

    M_DEL(mat);
    return delTime;
}

int main(){
    // Logger util.
    // SET_CNH_SHOW(1);
    // SET_CNH_BRIEF_MODE(1);
    // LOG("Program Started!");

    int cnt;
    scanf("%d", &cnt);

    double tot = 0;
    int i;
    for(i = 0;i < cnt;++i){
        double delTime = foo(i);
        tot += delTime;
    }
    
    FILE * fp = fopen("output.txt", "a");
    fprintf(fp, "%.6lf %.6lf \n", tot, tot/cnt);
    fclose(fp);
    return 0;
}