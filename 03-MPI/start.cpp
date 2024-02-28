#include <iostream>
#include <mpi.h>
void perform_something()
{
    std::cout << "something" << std::endl;
}
int main()
{
    // Initialize the environment for message passing
    MPI_Init(NULL, NULL);

    perform_something();

    // Let the compiler know Message Passing not
    // available post this
    MPI_Finalize();
    return 0;
}