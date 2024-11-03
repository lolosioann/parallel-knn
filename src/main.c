#include <stdio.h>
#include <stdlib.h>
#include "knn.h"
#include "mat_reader.h"

int main() {
    int n, d;  // Variables to hold matrix dimensions
    double* data;

    // Read data from a .mat file
    if (read_mat_file("data.mat", &data, &n, &d) != 0) {
        fprintf(stderr, "Failed to read .mat file\n");
        return -1;
    }

    // Allocate memory for k-nearest neighbor results
    int k = 3;  // Set the number of neighbors
    int* idx = (int*)malloc(n * k * sizeof(int));
    double* dst = (double*)malloc(n * k * sizeof(double));

    // Call KNN search function
    knn_search(data, data, d, n, k, idx, dst);

    // Output results for the first query point
    printf("Nearest neighbors for the first point:\n");
    for (int j = 0; j < k; j++) {
        printf("Neighbor %d: Index = %d, Distance = %f\n", j + 1, idx[j], dst[j]);
    }

    // Free allocated memory
    free(data);
    free(idx);
    free(dst);

    return 0;
}
