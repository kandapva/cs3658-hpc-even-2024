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
    bool flag=false;
    size_t N = pow(2,atoi(argv[1]));
    std::cout << "System size N = " << N << std::endl;
    float search_num = atof(argv[2]);
    // creating memory for array of size N
    input_array = (float *)malloc(sizeof(float) * N);

    for (int i = 0; i < N; i++)
        input_array[i] = i+1.0;

    // Serial implementation
    for (int i = 0; i < N; i++)
        if (input_array[i] == search_num)
            flag = true;
    if (flag)
        std::cout << "Element found ." << std::endl;
    else 
        std::cout << "Element not found ." <<std::endl; 
    // Your code goes here
    // Implement a parallel version of Linear search (naive)

    
    // Implement a parallel version of Linear search (chunked)


    // Your code goes till here
    return 0;
}