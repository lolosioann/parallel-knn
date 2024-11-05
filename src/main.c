#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdio.h>
#include "knn.h"
#include "mat_io.h"
#include "utils.h"

int main(int argc, char** argv)
{

    setenv("LD_LIBRARY_PATH", "/usr/local/MATLAB/R2024b/bin/glnxa64", 1);

    // Check for correct number of arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <corpus_file> <query_file> <no. of neighbors>\n", argv[0]);
        return -1;
    }

    char *p;
    int k;
    errno = 0;

    long conv = strtol(argv[3], &p, 10);

    // Check for errors during conversion
    if (errno == ERANGE)
    {
        fprintf(stderr, "Error: Integer out of range.\n");
        return 1;
    }
    else if (*p != '\0')
    {
        fprintf(stderr, "Error: Non-numeric characters detected.\n");
        return 1;
    }
    else if (conv > INT_MAX || conv < 0) {
        fprintf(stderr, "Error: Integer exceeds 'int' range.\n");
        return 1;
    }
    else
    {
        // Successful conversion
        k = (int)conv;
        printf("Converted integer: %d\n", k);
    }

    // Read data from a .mat file
    double_matrix_t *corpus = read_mat_file(argv[1]);
    if (corpus == NULL) {
        fprintf(stderr, "Failed to read .mat file\n");
        return -1;
    }

    double_matrix_t *query = read_mat_file(argv[2]);
    if (query == NULL) {
        fprintf(stderr, "Failed to read .mat file\n");
        return -1;
    }

    // // Allocate memory for k-nearest neighbor results
    // int* idx = (int*)malloc(query_n * k * sizeof(int));
    // double* dst = (double*)malloc(query_n * k * sizeof(double));

    // // Call KNN search function
    // knn_search(corpus, query, d, query_n, k, idx, dst);

    // // Output results to .mat file
    // write_mat_file("knn_results.mat", idx, dst, query_n, k);

    // Free allocated memory
    free_double_matrix(corpus);
    free_double_matrix(query);
    // free(idx);
    // free(dst);

    return 0;
}
