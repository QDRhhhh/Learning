#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include "helper/CNewbieHelper.h"
#include "matrix_utils.h"
#include "N3.h"
#include "N4.h"
#include "N6.h"

int main(){
    // Logger util.
    // SET_CNH_SHOW(1);
    // SET_CNH_BRIEF_MODE(1);
    // LOG("Program Started!");
    clock_t timerI = clock();

    int n, m;
    Matrix matrixObj, *mat = &matrixObj;
    M_INIT(mat);

    int ans = calMaxSubMatrixSum(mat);
    printf("The ans is: %d \n", ans);
    M_DEL(mat);

    clock_t timerF = clock();
    double delTime = (double)(timerF-timerI)/CLOCKS_PER_SEC;
    printf("Program Finished in %.4lf seconds!", delTime);
    // printf("Program Finished in %.4lf seconds!", (double)(timerF-timerI)/CLK_TCK);
    
    FILE * fp = fopen("output.txt", "w+");
    fprintf(fp, "%d %lf\n", ans, delTime);
    fclose(fp);
    return 0;
}