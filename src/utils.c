#include <stdlib.h>
#include <string.h>
#include "utils.h"

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

int_matrix_t *create_int_matrix(int rows, int cols) {

    int_matrix_t *matrix = malloc(sizeof(int_matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int **));
    if (matrix->data == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
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

void free_int_matrix(int_matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix);
}

// Implement quick-select to find the k smallest elements
void quick_select() {
}