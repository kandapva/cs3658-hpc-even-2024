#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int A[8];

    for(int i=0;i<8;i++){
        A[i] = 0;
        cout << A[i] << "\t";
    }
    
    #pragma omp parallel num_threads (8)
    {
        for(int i=0; i<8; i++)
            A[omp_get_thread_num()] += omp_get_thread_num();
    }
    cout << endl;
    for(int i=0;i<8;i++){
        cout << A[i] << "\t";
    }
    return 0;
}