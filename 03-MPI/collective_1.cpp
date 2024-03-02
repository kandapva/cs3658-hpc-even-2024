#include<iostream>
#include<mpi.h>

using namespace std;

int main(){
    int secret_code;
    MPI_Init(NULL, NULL); // Initialised MPI
    // Find my (processors') Unique ID - (also called as rank)
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    if(my_rank == 0)
        secret_code = 79;
    // Broadcast secret code to everyone
    MPI_Bcast(&secret_code, 1, MPI_INT, 0, MPI_COMM_WORLD);
    cout << "Received message: " << secret_code <<" My ID " << my_rank << endl;
    MPI_Finalize(); 
    return 0;
}