#ifndef UTILS_H
#define UTILS_H
typedef struct double_matrix_t{
    double **data;
    int rows;
    int cols;
} double_matrix_t;

double_matrix_t *create_double_matrix(int rows, int cols);

void free_double_matrix(double_matrix_t *matrix);

// Quick-select function prototype
void quick_select();

#endif  // UTILS_H
