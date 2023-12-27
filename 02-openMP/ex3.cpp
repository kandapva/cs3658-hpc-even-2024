#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <cmath>

using namespace std;

//  Exercise 3 - Searching an element in the array

int main(int argc, char **argv)
{
    float *input_array;
    size_t N = atoi(argv[1]); 
    // creating memory for array of size N
    input_array = (float *)malloc(sizeof(float) * N);
    // Your code goes here
    // Implement a parallel version of Linear search


    return 0;
}