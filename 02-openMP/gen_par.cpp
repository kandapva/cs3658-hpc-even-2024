
#include <iostream>
#include <omp.h>

#define N 100
#define N_ROWS 10
#define N_COLS 10

using namespace std;

int main()
{
    int *A;
    A = new int[N];
    int *B;
    B = new int[N_ROWS * N_COLS];
    float avg = 0.0;
    float avg1 = 0.0;

#pragma omp parallel shared(avg, avg1)
    {

#pragma omp for
        for (int i = 0; i < N; i++)
            A[i] = i + 1;
#pragma omp barrier

#pragma omp for reduction(+ : avg)
        for (int i = 0; i < N; i++)
            avg += A[i];
        if (omp_get_thread_num() == 0)
        {
            cout << "Average is " << avg / N << endl;
            // avg = 0.0;
        }

#pragma omp for collapse(2)
        for (int i = 0; i < N_ROWS; i++)
            for (int j = 0; j < N_COLS; j++)
            {
                int id = i * N_COLS + j;
                B[id] = id + 1;
            }

#pragma omp for nowait
        for (int i = 0; i < N_ROWS; i++)
            for (int j = 0; j < N_COLS; j++)
            {
                int id = i * N_COLS + j;
                B[id] = id + 1;
            }

#pragma omp for reduction(+ : avg1)
        for (int i = 0; i < N; i++)
            avg1 += B[i];

        if (omp_get_thread_num() == 0)
        {
            cout << "Average is " << avg1 / N << endl;
            // avg = 0.0;
        }
    }
    avg /= N;
    cout << "Average is " << avg << endl;

    delete A;
    delete B;

    return 0;
}