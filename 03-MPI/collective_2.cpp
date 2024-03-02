#include<iostream>
#include<mpi.h>

using namespace std;

int main(){
    int *series_data;
    int *my_data;
    series_data = new int[100];
    MPI_Init(NULL, NULL); 
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int num_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    if(my_rank == 1 && num_procs>1)
    {  
        for(int i=0;i<100;i++)
            series_data[i] = i+1;    
    }
    MPI_Barrier(MPI_COMM_WORLD);
    my_data = new int[25];
    MPI_Scatter(series_data,25,MPI_INT,my_data,25,MPI_INT,1,MPI_COMM_WORLD);
    float my_avg = 0.0;
    float tmp_data[4];
    for(int i=0; i<25;i++)
        my_avg += my_data[i]; 
    MPI_Gather(&my_avg,1,MPI_FLOAT,&tmp_data,1,MPI_FLOAT,0,MPI_COMM_WORLD);
    if(my_rank == 0)
    {
        float local_avg = 0.01 * (tmp_data[0] + tmp_data[1] + tmp_data[2] + tmp_data[3]);
        cout << "Average of 100 numbers is " << local_avg << endl;
    }
    MPI_Finalize(); 
    return 0;
}