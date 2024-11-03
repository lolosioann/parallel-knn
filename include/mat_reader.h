#ifndef MAT_READER_H
#define MAT_READER_H

#include "/usr/local/MATLAB/R2024b/extern/include/matrix.h"  // MATLAB Matrix Library
#include "/usr/local/MATLAB/R2024b/extern/include/mat.h"     // MATLAB MAT-File Library

// Function to read data from a .mat file
// Parameters: filename, pointer to data array, and variables for dimensions
int read_mat_file(const char* filename, double** data, int* n, int* d);

#endif // MAT_READER_H