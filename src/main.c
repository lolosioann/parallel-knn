#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>
#include <stdio.h>
#include "knn.h"
#include "mat_io.h"
#include "utils.h"

int main(int argc, char** argv)
{

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
    // int_matrix_t *idx = create_int dir(query->rows, k);
    // double_matrix_t *dst = create_double_array(query->rows * k);

    // // Call KNN search function
    // knn_search(corpus, query, k, idx, dst);

    // // Output results to .mat file
    // write_mat_file("knn_results.mat", idx, dst, query_n, k);

    // Free allocated memory
    free_double_matrix(corpus);
    free_double_matrix(query);
    // free_int_matrix(idx);
    // free_double_matrix(dst);

    return 0;
}
