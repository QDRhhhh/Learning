#include "N6.h"

// This function will calculate the max sum of the sub-Matrix
// in mat.
int calMaxSubMatrixSum(Matrix * mat){
    int i, j, k, l, x, y, ans = 0;
    // Iterate the left-top key point.
    for(i = 0; i < mat->n; ++i){
        for(j = 0; j < mat->m; ++j){
            // Iterate the right-bottom key point.
            for(k = i+1; k <= mat->n; ++k){
                for(l = j+1; l <= mat->m; ++l){
                    int tmp = 0;
                    // Calculate the sum in region from [k][l] to [i+1][j+1].
                    for(x = i+1; x <= k; ++x){
                        for(y = j+1; y <= l; ++y){
                            tmp += M_ELE(mat, x, y);
                        }
                    }
                    // Update the answer if we get larger sum.
                    ans = tmp > ans ? tmp : ans;
                }
            }
        }
    }
    return ans;
}

int getMethod(){
    return 6;
}
