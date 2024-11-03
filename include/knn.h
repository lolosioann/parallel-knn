#ifndef KNN_H
#define KNN_H

// KNN search function prototype
void knn_search(double* C, double* Q, int d, int n, int k, int* idx, double* dst);

// Function to compute squared norms (used in distance calculations)
void compute_squared_norms(double* data, double* norms, int n, int d);

#endif  // KNN_H
