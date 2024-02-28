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
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
if (world_size%2 == 0){
    if (my_rank % 2 == 0) // Even Processors send message
    {
        int message = message_to_be_sent(my_rank);
        MPI_Send(&message, 1, MPI_INT, my_rank + 1, 0, MPI_COMM_WORLD);
    }
    else // Adjacent odd processors receive message
    {
        int message;
        MPI_Recv(&message, 1, MPI_INT, my_rank - 1, 0, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);
        print_message(my_rank-1, message);
    }
}
MPI_Finalize(); // MPI Terminated
return 0;
}