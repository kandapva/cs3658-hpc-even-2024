// C++ Program to show how to use

#include <iostream>
#include <omp.h>
// Library effective with Linux
#include <unistd.h>

using namespace std;
void i_am_lazy(int i){
    sleep(i*0.1);
}
// Driver code
int main()
{
double start = 0.0, duration = 0.0; 
// Different schedule funcitons
start = omp_get_wtime();
#pragma omp parallel for schedule(static, 5)
for(int i=0;i<100;i++)
    i_am_lazy(i);
duration = omp_get_wtime() - start;
cout << "Time for static scheduling - " << duration << "s" << endl;

start = omp_get_wtime();
#pragma omp parallel for schedule(dynamic, 5)
for(int i=0;i<100;i++)
    i_am_lazy(i);
duration = omp_get_wtime() - start;
cout << "Time for Dynamic scheduling - " << duration << "s" << endl;

start = omp_get_wtime();
#pragma omp parallel for schedule(guided, 5)
for(int i=0;i<100;i++)
    i_am_lazy(i);
duration = omp_get_wtime() - start;
cout << "Time for Guided scheduling - " << duration << "s" << endl;
return 0;
}
