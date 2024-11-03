#include <stdio.h>
#include <stdlib.h>
#include "mat_reader.h"

// Reads a matrix from a .mat file and stores it in a C array
int read_mat_file(const char* filename, double** data, int* n, int* d) {
    MATFile* matFile;
    mxArray* matArray;

    // Open the .mat file
    matFile = matOpen(filename, "r");
    if (matFile == NULL) {
        fprintf(stderr, "Error opening .mat file %s\n", filename);
        return -1;
    }

    // Read the matrix (assuming there's only one variable)
    matArray = matGetVariable(matFile, "data");  // Replace "data" with the variable name
    if (matArray == NULL) {
        fprintf(stderr, "Error reading variable from .mat file %s\n", filename);
        matClose(matFile);
        return -1;
    }

    // Get dimensions
    *n = (int)mxGetM(matArray);
    *d = (int)mxGetN(matArray);

    // Allocate memory for the data array
    *data = (double*)malloc((*n) * (*d) * sizeof(double));
    if (*data == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        mxDestroyArray(matArray);
        matClose(matFile);
        return -1;
    }

    // Copy data from the MATLAB array to the C array
    double* matData = mxGetPr(matArray);
    for (int i = 0; i < (*n) * (*d); i++) {
        (*data)[i] = matData[i];
    }

    // Clean up
    mxDestroyArray(matArray);
    matClose(matFile);

    return 0;  // Success
}
