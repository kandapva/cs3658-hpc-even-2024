#include<iostream>
#include<mpi.h>
int main()
{
MPI_Init(NULL, NULL); // Initialised MPI
// Find my (processors') Unique ID - (also called as rank)
int my_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
// Find the total number of processors
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
MPI_Barrier(MPI_COMM_WORLD);
std::cout << "My rank is " << my_rank << " among " << world_size << "Processors.." << std::endl;
MPI_Finalize(); // MPI Terminated
return 0;
}