#include <iostream>
#include <omp.h>

#define N 100

using namespace std;

int main(){
    // Example 1
    int *A;
    A = new int[N];
    float avg = 0.0;
    for (int i = 0; i < N; i++)
        A[i] = i + 1;
    for (int i = 0; i < N; i++)
        avg += A[i];

    cout << "Average is " << avg/N << endl;

    // Example 2
    for (int i = 0; i < 10; i++)
        cout << A[i] << endl;
    int block_size = 0;

    // Use #pragma omp parallel for
    for (int i = 0; i < 10; i++)
    {
        A[i] += block_size;
        block_size += 5;
    }
    for(int i=0; i<10;i++)
        cout << A[i] << endl;

    // Example 4
    for (int i = 1; i < N; i++)
    {
        A[i] += A[i - 1];
    }

    return 0;
}