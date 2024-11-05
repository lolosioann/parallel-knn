#include <stdio.h>
#include <stdlib.h>
#include "mat_io.h"
#include "utils.h" 

// Reads a matrix from a .mat file and stores it in a C array
double_matrix_t *read_mat_file(const char* filename) {
    MATFile* matFile;
    mxArray* matArray;

    // Open the .mat file
    matFile = matOpen(filename, "r");
    if (matFile == NULL) {
        fprintf(stderr, "Error opening .mat file %s\n", filename);
        return NULL;
    }

    // Read the matrix (assuming there's only one variable)
    matArray = matGetVariable(matFile, "C");  // C is the name of the variable in the .mat file
    if (matArray == NULL) {
        fprintf(stderr, "Error reading variable from .mat file %s\n", filename);
        matClose(matFile);
        return NULL;
    }

    // Get dimensions
    int rows = (int)mxGetM(matArray);
    int cols = (int)mxGetN(matArray);

    double_matrix_t *matrix = create_double_matrix(rows, cols);

    // Allocate memory for the data array
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        mxDestroyArray(matArray);
        matClose(matFile);
        return NULL;
    }

    // Copy data from the MATLAB array to the C array
    double* matData = mxGetPr(matArray);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = matData[i * matrix->cols + j];
        }
    }

    // Clean up
    mxDestroyArray(matArray);
    matClose(matFile);

    return matrix;  // Success
}

// Writes the k-NN results to a .mat file
// int write_mat_file(const char* filename, int* idx, double* dst, int query_n, int k) {
    // MATFile* matFile;
    // mxArray* idxArray;
    // mxArray* dstArray;

    // // Create MATLAB arrays for indices and distances
    // idxArray = mxCreateDoubleMatrix(query_n, k, mxREAL);
    // dstArray = mxCreateDoubleMatrix(query_n, k, mxREAL);
    // if (idxArray == NULL || dstArray == NULL) {
    //     fprintf(stderr, "Memory allocation error\n");
    //     if (idxArray != NULL) mxDestroyArray(idxArray);
    //     if (dstArray != NULL) mxDestroyArray(dstArray);
    //     return -1;
    // }

    // // Copy data to MATLAB arrays
    // double* idxData = mxGetPr(idxArray);
    // double* dstData = mxGetPr(dstArray);
    // for (int i = 0; i < query_n * k; i++) {
    //     idxData[i] = (double)idx[i];
    //     dstData[i] = dst[i];
    // }

    // // Open the .mat file for writing
    // matFile = matOpen(filename, "w");
    // if (matFile == NULL) {
    //     fprintf(stderr, "Error opening .mat file %s\n", filename);
    //     mxDestroyArray(idxArray);
    //     mxDestroyArray(dstArray);
    //     return -1;
    // }

    // // Write the arrays to the .mat file
    // if (matPutVariable(matFile, "idx", idxArray) != 0 || matPutVariable(matFile, "dst", dstArray) != 0) {
    //     fprintf(stderr, "Error writing variables to .mat file %s\n", filename);
    //     mxDestroyArray(idxArray);
    //     mxDestroyArray(dstArray);
    //     matClose(matFile);
    //     return -1;
    // }

    // // Clean up
    // mxDestroyArray(idxArray);
    // mxDestroyArray(dstArray);
    // matClose(matFile);

    // return 0;  // Success
//}
