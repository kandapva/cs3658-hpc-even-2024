#include <iostream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

// Basic functions in OMP header

int main(int argc, char **argv)
{
    omp_set_dynamic(0);
    // 1) Get the unique thread id
    int thread_id = omp_get_thread_num();

    // 2) Get number of threads available
    int num_threads = omp_get_num_threads();

    // Uncomment the following line to set threads manually
    // omp_set_num_threads(NUMBER_OF_THREADS); // This is one way

    cout << "START - Thread ID/Num Threads - " << thread_id << "/" << num_threads << "/" << omp_get_num_threads() << endl;
    cout << endl;
    // 3) Variables declared inside the parallel region is scoped only within the parallel region
    // num_threads (4) is second way to set the number of threads
    // There is other way where you can change the environment variable export OMP_NUM_THREADS=4
#pragma omp parallel num_threads (4)
    {
        int thread_id_ = omp_get_thread_num();
        int num_threads_ = omp_get_num_threads();
        cout << "$) Thread ID/Num Threads - " << thread_id_ << "/" << num_threads_ << "/" << omp_get_num_threads() << endl;
    }
    cout << endl;
    cout << "MID1 - Thread ID/Num Threads - " << thread_id << "/" << num_threads << "/" << omp_get_num_threads() << endl;
    cout << endl;
    // Here lets try to use the variable thread_id declared outside 
#pragma omp parallel num_threads (4)
    {
        thread_id = omp_get_thread_num();
        cout << "*) Thread ID out/Thread ID in - " << thread_id << "/" << omp_get_thread_num() << endl;
    }
    cout << endl;
    cout << "MID2 - Thread ID/Num Threads - " << thread_id << "/" << num_threads << "/" << omp_get_num_threads() << endl;
    cout << endl;
    // Use of private keyword
#pragma omp parallel num_threads (4) private (thread_id)
    {
        thread_id = omp_get_thread_num();
        cout << "*) Thread ID out/Thread ID in - " << thread_id << "/" << omp_get_thread_num() << endl;
    }
    cout << endl;
    cout << "EXIT - Thread ID/Num Threads - " << thread_id << "/" << num_threads << endl;


    return 0;
}