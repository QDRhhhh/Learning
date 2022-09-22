#include "N3.h"


// This function will preprocess the sumM and make it to
// a matrix that has the following feature:
// sumM[I][J] = ${ \sum^{I}_{i} mat[i][J] }$
void initSumMatrix(Matrix * sumM, Matrix * mat){
    M_CP_SHAPE(sumM, mat);
    int i, j;
    for(j = 1; j <= mat->m; ++j){
        M_ELE(sumM, 0, j) = 0;
    }
    // sumM[I][J] = ${ \sum^{I}_{i} mat[i][J] }$
    //            = sumM[I-1][J] + mat[I][J]
    for(i = 1; i <= mat->n; ++i){
        for(j = 1; j <= mat->m; ++j){
            M_ELE(sumM, i, j) = M_ELE(sumM, i-1, j) + M_ELE(mat, i, j);
        }
    }
    return;
}

// This function will fold the sumM and make foldM to
// a matrix that has the following feature:
// sumM[J] = { \sum_{l1<=i<l2} mat[i][J] }
void calFoldMatrix(Matrix * foldM, Matrix * sumM, int l1, int l2){
    int j;
    // Using the feature of prefix sum algorithm.
    for(j = 1; j <= sumM->m; ++j){
        M_ELE(foldM, 1, j) = M_ELE(sumM, l2, j) - M_ELE(sumM, l1-1, j);
    }
    return;
}

// This function will calculate the max sum of the sub-segment
// in vec.
int calMaxSubSegmentSum(Matrix * vec){
    int j, curSum = 0, maxSum = 0;
    for(j = 1; j <= vec->m; ++j){
        curSum += M_ELE(vec, 1, j);
        curSum = curSum < 0 ? 0 : curSum;           // curSum = max(curSum, 0);
        maxSum = curSum > maxSum ? curSum : maxSum; // maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

// This function will calculate the max sum of the sub-Matrix
// in mat.
int calMaxSubMatrixSum(Matrix * mat){
    // Logger util.
    // SET_CNH_SHOW(0);
    // SET_CNH_BRIEF_MODE(1);

    int ret = -0x3F3F3F3F;

    // This matrix is to store the 2d-prefix sum on the n-axis.
    // That is, sumM[I][J] = ${ \sum^{I}_{i} mat[i][J] }$
    Matrix sumMObj, * sumM = &sumMObj;
    initSumMatrix(sumM, mat);
    // M_SHOW(sumM); // For debug.
    
    // This matrix is to store the segment sum of mat on the
    // n-axis, calculated from sumM.
    // That is, foldM(l1,l2)[J] = ${ \sum_{l1<=i<l2} mat[i][J] }$
    Matrix foldMObj, * foldM = &foldMObj;
    foldM->n = 1, foldM->m = mat->m;
    M_NEW(foldM);

    // Iterate the upper and lower bounds, then change the problem
    // into max sub-segment sum.
    int l1, l2;
    for(l1 = 1; l1 <= mat->n; ++l1){
        for(l2 = l1+1; l2 <= mat->n+1; ++l2){
            calFoldMatrix(foldM, sumM, l1, l2);
            int tmp = calMaxSubSegmentSum(foldM);
            ret = tmp > ret ? tmp : ret;    // ret = max(ret, tmp);
        }
    }
    
    return ret;
}

