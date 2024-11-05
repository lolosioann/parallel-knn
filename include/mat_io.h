#ifndef MAT_IO_H
#define MAT_IO_H

#include "/usr/local/MATLAB/R2024b/extern/include/matrix.h"  // MATLAB Matrix Library
#include "/usr/local/MATLAB/R2024b/extern/include/mat.h"
# include "utils.h"     // MATLAB MAT-File Library

// Function to read data from a .mat file
// Parameters: filename, pointer to data array, and variables for dimensions
double_matrix_t *read_mat_file(const char* filename);

int write_mat_file(const char* filename, int* idx, double* dst, int query_n, int k);

#endif // MAT_READER_H