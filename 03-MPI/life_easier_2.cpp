#include<iostream>
#include<mpi.h>

using namespace std;

int main(){
    float *local_vector;
    float *full_vector;
    MPI_Init(NULL, NULL); 
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    if(my_rank == 0){
        full_vector = new int[num_procs*25+10];
        for (int i = 1; i < num_procs * 25 + 11; i++)
            full_vector = 1000 - i;
    }
    // Your code goes here
    MPI_Scatterv(); // Find and fill
// Do something here on full_vector
    MPI_Gatherv(); // Find and fill

    MPI_Finalize();
}