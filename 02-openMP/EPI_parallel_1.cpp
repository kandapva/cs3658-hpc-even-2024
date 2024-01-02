/******************************************************************************

ESTIMATE the value of pi using Monte-Carlo simulation (Parallel code)

*******************************************************************************/
#include <iostream>
#include <random>
#include <cmath>
#include <omp.h>

#define RADIUS 10.0
#define N_SAMPLES 10000
#define NUM_THREADS 4

using namespace std;

float get_rand_num()
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1.0 * RADIUS, RADIUS);
    return (float)dis(gen);
}

int main()
{
    float pi_estimated = 0.0;
    float A[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
        A[i] = 0.0;
    omp_set_num_threads(NUM_THREADS);
    double start = omp_get_wtime();
#pragma omp parallel
    {
        size_t inside_circle = 0;
        int thread_id = omp_get_thread_num();
        for (size_t i = 0; i < N_SAMPLES / NUM_THREADS; i++)
        {
            float x_ = get_rand_num();
            float y_ = get_rand_num();
            if (pow((x_ * x_ + y_ * y_), 0.5) < RADIUS)
                inside_circle++;   
        }
        A[thread_id] = 4.0 * (inside_circle * NUM_THREADS / (N_SAMPLES * 1.0));
    }
    for (int i = 0; i < NUM_THREADS; i++)
        pi_estimated += A[i];
    pi_estimated /= 4;
    double duration = omp_get_wtime() - start;
    cout << "Original value of pi is " << M_PI << endl;
    cout << "Estimated value of pi is " << pi_estimated << endl;
    cout << "Time to estimate pi is " << duration << "s" << endl;
    return 0;
}