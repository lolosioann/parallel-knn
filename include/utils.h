#ifndef UTILS_H
#define UTILS_H
typedef struct double_matrix_t{
    double **data;
    int rows;
    int cols;
} double_matrix_t;

typedef struct int_matrix_t{
    int **data;
    int rows;
    int cols;
} int_matrix_t;

double_matrix_t *create_double_matrix(int rows, int cols);
int_matrix_t *create_int_matrix(int rows, int cols);

void free_double_matrix(double_matrix_t *matrix);
void free_int_matrix(int_matrix_t *matrix);

void quick_select();

#endif  // UTILS_H