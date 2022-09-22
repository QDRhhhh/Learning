#ifndef __MATRIX_UTILS__
#define __MATRIX_UTILS__

#include "stdio.h"
#include "stdlib.h"

/****************************************************
 * Matrix Utils Lib 1.0                             *
 * ------------------------------------------------ *
 * Last Edit: 2022.9.22                             *
 ****************************************************/

// Macro Function:
// - The function returns the left value of the elements in the
// - matrix indexed by the "pos_x" and "pos_y".
//
// Usage:
// - Just use M_ELE(mat_ptr, pos_x, pos_y) as a right value or 
// - left value. 
// - eg: [ M_ELE(mat_ptr, pos_x, pos_y) = ... ] 
// - "mat_ptr" here is the a pointer to a Matrix type variable.
// - "pos_x" and "pos_y" here is the position of the target elements.
#define M_ELE(MATRIX_P, POS_N, POS_M) *(MATRIX_P->elePtr + MATRIX_P->m * (POS_N) + (POS_M))

// Macro Function:
// - This function is used to allocate the memory of the
// - (only) elements of Matrix type variable.
//
// Usage:
// - [ M_NEW(mat_ptr); ]
// - "mat_ptr" here is the a pointer to a Matrix type variable.
#define M_NEW(MATRIX_P) do{                                                                \
    MATRIX_P->elePtr = (int * )malloc( (MATRIX_P->n+1) * (MATRIX_P->m+1) * sizeof(int) );   \
}while(0);

// Macro Function:
// - This function is used to deal with the memory of the
// - (only) elements of Matrix type variable.
// - That means, you should deal with the memory pointed by
// - the "mat_ptr" directly!
//
// Usage:
// - [ M_DEL(mat_ptr); ]
// - "mat_ptr" here is the a pointer to a Matrix type variable.
#define M_DEL(MATRIX_P) do{ \
    free(MATRIX_P->elePtr); \
}while(0);

// Macro Function:
// - This function is used to initialize a matrix with data
// - given from console.
// - First it reads two integers, n and m, which represent
// - the shape of the matrix.
// - Then it reads the elements of the matrix, which are 
// - organized as n rows and m columns. 
// - It will also allocate memory for it.
//
// Usage:
// - [ M_INIT(mat_ptr); ]
// - "mat_ptr" here is the a pointer to a Matrix type variable.
#define M_INIT(mat) do{ \
    /* Read in the shape of matrix. */ \
    scanf("%d %d", &(mat->n), &(mat->m)); \
    /* Allocate the memory. */ \
    M_NEW(mat); \
    /* Read in the elements one by one. */ \
    int read_mat_it1, read_mat_it2; \
    for(read_mat_it1 = 1; read_mat_it1 <= mat->n; ++read_mat_it1){ \
        for(read_mat_it2 = 1; read_mat_it2 <= mat->m; ++read_mat_it2){ \
            scanf("%d", &M_ELE(mat, read_mat_it1, read_mat_it2)); \
        } \
    } \
}while(0)\

#define M_SHOW(mat) do{ \
    int read_mat_it1, read_mat_it2; \
    printf("n: %d, m: %d;\n[\n", mat->n, mat->m); \
    for(read_mat_it1 = 1; read_mat_it1 <= mat->n; ++read_mat_it1){ \
        for(read_mat_it2 = 1; read_mat_it2 <= mat->m; ++read_mat_it2){ \
            printf(" %d", M_ELE(mat, read_mat_it1, read_mat_it2)); \
        } \
        printf("\n"); \
    } \
    printf("]\n"); \
}while(0)

// Macro Function:
// - This function is used to copy the shape of matrix
// - from "fromMat" to "toMat". And also allocate the
// - memory.
//
// Usage:
// - [ M_CP_SHAPE(toMat, fromMat); ]
// - "toMat" here is the a pointer to the Matrix type variable
// - to be modified, while "fromMat" provides the shape.
#define M_CP_SHAPE(toMat, fromMat) do{ \
    toMat->m = fromMat->m, toMat->n = fromMat->n; \
    M_NEW(toMat); \
}while(0)


typedef struct MatrixStruct{
    int n, m;
    int * elePtr;
} Matrix;

#endif