#include "utils.h"
#include <stdlib.h>
#include <string.h>

double_matrix_t *create_double_matrix(int rows, int cols) {

    double_matrix_t *matrix = malloc(sizeof(double_matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double **)malloc(rows * sizeof(double **));
    if (matrix->data == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
        if (matrix->data[i] == NULL) {
            // Free memory allocated so far
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            return NULL;
        }
    }

    return matrix;
}

void free_double_matrix(double_matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix);
}

// Implement quick-select to find the k smallest elements
void quick_select() {
    // Implement quick-select (left as an exercise or placeholder for now)
    // This function should partition distances and indices arrays to find k smallest elements
}