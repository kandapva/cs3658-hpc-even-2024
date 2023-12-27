#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <cmath>

using namespace std;

#define matrix(i, j) input_matrix[ (j)*N + i ]

void Initialize(float *input_array, float *output_array, float *input_matrix, size_t N)
{
    for (int i = 0; i < N; i++)
    {
        input_array[i] = i * 0.1;
        output_array[i] = 0.0;
        for (int j = 0; j < N; j++)
            matrix(i, j) = (i - j) * 1.29;
    }
}

void display(float *a, int N)
{
    std::cout << std::endl << "N = " << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << a[i] << "\t";
    std::cout << std::endl;
}

//  Exercise 2 - Matrix-Vector multiplication

int main(int argc, char **argv)
{

    int N = pow(2, atoi(argv[1]));
    omp_set_num_threads(8);
    std::cout << "System size N = " << N << std::endl;

    float *input_matrix, *input_array, *output_array;
    // creating memory for array of size N
    input_array = (float *)malloc(sizeof(float) * N);
    input_matrix = (float *)malloc(sizeof(float) * N * N);
    output_array = (float *)malloc(sizeof(float) * N);

    Initialize(input_array, output_array, input_matrix, N);

    // display(input_matrix, N*N);
        

    // Serial Implementation:

    double start = omp_get_wtime();
    #pragma omp parallel num_threads (1)
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            output_array[i] += matrix(i,j) * input_array[j];

    double end = omp_get_wtime() - start;
    std::cout << "Serial time - " << end << "s" << std::endl;

    Initialize(input_array, output_array, input_matrix, N);

    // display(input_matrix, N * N);

    // Method 1 : Naive parallel approach (1)

    Initialize(input_array, output_array, input_matrix, N);
    start = omp_get_wtime();
#pragma omp parallel for 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            output_array[i] += matrix(i, j) * input_array[j];

    end = omp_get_wtime() - start;
    std::cout << "Method 1 time - " << end << "s" << std::endl;

    // Method 2 : Naive parallel approach (1)

    Initialize(input_array, output_array, input_matrix, N);
    start = omp_get_wtime();
    for (int i = 0; i < N; i++)
    #pragma omp parallel for
        for (int j = 0; j < N; j++)
            output_array[i] += matrix(i, j) * input_array[j];

    end = omp_get_wtime() - start;
    std::cout << "Method 2 time - " << end << "s" << std::endl;

    // Method 3 : Chunked version (ROW)

    // Method 4 : Chunked version (Column)


    free(input_matrix);
    free(input_array);
    free(output_array);

    return 0;
}