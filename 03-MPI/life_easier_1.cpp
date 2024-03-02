#include<iostream>
#include<mpi.h>

using namespace std;

int main(){
    float local_sum = 0.0;
    float global_sum = 0.0;
    float *all_sum;
    MPI_Init(NULL, NULL); 
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    
    for (int i = 1; i < 100; i++)
        local_sum += my_rank * 100 + i;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(my_rank == 0)
        cout << "Sum " << global_sum << endl;
    all_sum = new float[num_procs];
    MPI_Allreduce(&local_sum, all_sum, 1, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
    
    if (my_rank == 0)
    {
        float local_avg = (all_sum[0] + all_sum[1] + all_sum[2] + all_sum[3]);
        cout << "Sum avail all " << local_avg << endl;
    }
    MPI_Finalize();
}