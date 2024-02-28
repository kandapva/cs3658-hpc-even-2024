#include<iostream>
#include<mpi.h>
int message_to_be_sent(int proc_id){
return proc_id + 7;
}
void print_message(int proc_id, int message){
    std::cout <<"Processor " << proc_id+1 << " received " << message << " from Processor " << proc_id << std::endl;
}

int main()
{
MPI_Init(NULL, NULL); // Initialised MPI
// Find my (processors') Unique ID - (also called as rank)
int my_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
if (my_rank == 0)
{
    int message = 404;
    MPI_Send(&message, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
}
if (my_rank == 2)
{
    int message;
    MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    std::cout << "Received message: " << message << std::endl;
}
MPI_Finalize(); // MPI Terminated
return 0;
}