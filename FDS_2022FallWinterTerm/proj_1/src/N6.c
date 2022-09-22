#include "N6.h"

int calMaxSubMatrixSum(Matrix * mat){
    int i, j, k, l, x, y, ans = -0x3F3F3F3F;
    for(i = 0; i < mat->n; ++i){
        for(j = 0; j < mat->m; ++j){
            for(k = i+1; k <= mat->n; ++k){
                for(l = j+1; l <= mat->m; ++l){
                    int tmp = 0;
                    for(x = i+1; x <= k; ++x){
                        for(y = j+1; y <= l; ++y){
                            tmp += M_ELE(mat, x, y);
                        }
                    }
                    ans = tmp > ans ? tmp : ans;
                }
            }
        }
    }
    return ans;
}