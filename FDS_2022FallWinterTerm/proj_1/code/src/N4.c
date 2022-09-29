#include "N4.h"

// This function will preprocess the sumM and make it to
// a matrix that has the following feature:
// sumM[I][J] = ${ \sum^{I,J}_{i,j} mat[i][j] }$
void initSumMatrix(Matrix * sumM, Matrix * mat){
    M_CP_SHAPE(sumM, mat);
    int i, j;
    for(j = 1; j <= mat->m; ++j){
        M_ELE(sumM, 0, j) = 0;
    }
    for(i = 1; i <= mat->n; ++i){
        M_ELE(sumM, i, 0) = 0;
    }
    // sumM[I][J] = ${ \sum^{I,J}_{i,j} mat[i][j] }$
    //            = sumM[I-1][J] + sumM[I-1][J-1] - sumM[I-1][J-1] + mat[I][J]
    for(i = 1; i <= mat->n; ++i){
        for(j = 1; j <= mat->m; ++j){
            M_ELE(sumM, i, j) = M_ELE(sumM, i-1, j) + M_ELE(sumM, i, j-1) - M_ELE(sumM, i-1, j-1) + M_ELE(mat, i, j);
        }
    }
}

// This function will calculate the max sum of the sub-Matrix
// in mat.
int calMaxSubMatrixSum(Matrix * mat){
    // This matrix is to store the 2d-prefix sum on the both 
    // n-axis and m-axis.
    // That is, sumM[I][J] = ${ \sum^{I,J}_{i,j} mat[i][j] }$
    Matrix sumMObj, * sumM = &sumMObj;
    initSumMatrix(sumM, mat);
    // M_SHOW(sumM); // For debug.

    int i, j, k, l, x, y, ans = 0;
    // Iterate the left-top key point.
    for(i = 0; i < mat->n; ++i){
        for(j = 0; j < mat->m; ++j){
            // Iterate the right-bottom key point.
            for(k = i+1; k <= mat->n; ++k){
                for(l = j+1; l <= mat->m; ++l){
                    int tmp = 0;
                    // Calculate the sum in region from [k][l] to [i+1][j+1].
                    tmp = M_ELE(sumM, k, l) + M_ELE(sumM, i, j) - M_ELE(sumM, k, j) - M_ELE(sumM, i, l);
                    // Update the answer if we get larger sum.
                    ans = tmp > ans ? tmp : ans;
                }
            }
        }
    }
    return ans;
}

int getMethod(){
    return 4;
}