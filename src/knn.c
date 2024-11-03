#include <math.h>
#include <cblas.h>
#include <stdlib.h>
#include "knn.h"
#include "utils.h"  // For quick_select

// Function to compute squared norms
void compute_squared_norms(double* data, double* norms, int n, int d) {
    for (int i = 0; i < n; i++) {
        norms[i] = 0.0;
        for (int j = 0; j < d; j++) {
            norms[i] += data[i * d + j] * data[i * d + j];
        }
    }
}

// KNN search function
void knn_search(double* C, double* Q, int d, int n, int k, int* idx, double* dst) {
    // Allocate memory for squared norms
    double* C_squared_norms = (double*)malloc(n * sizeof(double));
    double* Q_squared_norms = (double*)malloc(n * sizeof(double));

    // Compute squared norms
    compute_squared_norms(C, C_squared_norms, n, d);
    compute_squared_norms(Q, Q_squared_norms, n, d);

    // Allocate distance matrix
    double* D = (double*)malloc(n * n * sizeof(double));

    // Calculate initial distances using norms
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i * n + j] = C_squared_norms[i] + Q_squared_norms[j];
        }
    }

    // Use OpenBLAS for -2 * C * Q^T part
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, n, n, d, -2.0, C, d, Q, d, 1.0, D, n);

    // Take square root for final distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i * n + j] = sqrt(D[i * n + j]);
        }
    }

    // Find k nearest neighbors for each query point
    for (int i = 0; i < n; i++) {
        quick_select(&D[i * n], &idx[i * k], 0, n - 1, k);

        // Store k nearest distances
        for (int j = 0; j < k; j++) {
            dst[i * k + j] = D[i * n + idx[i * k + j]];
        }
    }

    // Cleanup
    free(C_squared_norms);
    free(Q_squared_norms);
    free(D);
}
