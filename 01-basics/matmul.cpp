#include <iostream>
#include <chrono>

using namespace std::chrono;

int main(){
    int A[100][100], B[100][100], C[100][100];
    for(int i=0; i<100;i++)
        for(int j=0; j<100;j++){
            A[i][j] = i+j;
            B[i][j] = i-j;
            C[i][j] = 0;
        }
    auto start = high_resolution_clock::now();
    // Method 1:
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            for(int k=0;k<100;k++)
                C[i][j] += A[i][k]*B[k][j];

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by method 1: "
         << duration.count() << " microseconds" << std::endl;

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
        {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }

    // Method 2:
    start = high_resolution_clock::now();
    for (int j = 0; j < 100; j++)
        for (int k = 0; k < 100; k++)
            for (int i = 0; i < 100; i++)
                C[i][j] += A[i][k] * B[k][j];

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    std::cout << "Time taken by method 2: "
              << duration.count() << " microseconds" << std::endl;

    return 0;
}