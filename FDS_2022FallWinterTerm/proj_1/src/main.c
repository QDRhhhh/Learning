#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#include "matrix_utils.h"
#include "N3.h"

#define MAX_N 1024
#define MAX_M 1024

#include "helper/CNewbieHelper.h"
#include "matrix_utils.h"
#include "N6.h"

int main(){
    // Logger util.
    SET_CNH_SHOW(1);
    SET_CNH_BRIEF_MODE(1);
    LOG("Program Started!");
    clock_t timerI = clock();

    int n, m;
    Matrix matrixObj, *mat = &matrixObj;
    M_INIT(mat);

    printf("The ans is: %d \n", calMaxSubMatrixSum(mat));
    M_DEL(mat);

    clock_t timerF = clock();
    LOG("Program Finished in %.4lf seconds!", (double)(timerF-timerI)/CLOCKS_PER_SEC); // For Mac.
    // LOG("Program Finished in %.4lf seconds!", (double)(timerF-timerI)/CLK_TCK); // For Win/Lin.
    return 0;
}