# Parallel k-NN

## Summary
This project implements a parallel version of the k-Nearest Neighbors (k-NN) algorithm. The parallelization aims to improve the performance and efficiency of the k-NN algorithm, making it suitable for large datasets.

## Requirements
- Any Linux installation
- Matlab v.R2024b
- OpenBLAS

## Instructions

### Building the Project
1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/parallel-knn.git
    or
    git clone git@github.com:lolosioann/parallel-knn.git
    cd parallel-knn
    ```

2. Run Make to build the project:
    ```sh
    make
    ```

### Running the Program
After building the project, you can run the executable:
```sh
./build/parallel_knn <corpus_file> <query_file> <k>
```