#include <iostream>
#include <omp.h>
#include <string>

using namespace std;

int main()
{

    int a_shared, a_private, a_first_private;
    a_shared = 100;
    a_private = 24;
    a_first_private = 420;
    cout << endl;
#pragma omp parallel shared(a_shared) private(a_private) firstprivate(a_first_private) num_threads(1)
    {
        string string_to_print;
        int tID = omp_get_thread_num();
        a_shared += tID + 1;
        a_private += tID + 1;
        a_first_private += tID + 1;
        string_to_print = "TID =" + to_string(tID) + " as = " + to_string(a_shared) + " ap = " + to_string(a_private) + " afp = " + to_string(a_first_private) + " ";
        cout << string_to_print << endl;
    }
    cout << endl;
    string string_to_print = "After - as = " + to_string(a_shared) + " ap = " + to_string(a_private) + " afp = " + to_string(a_first_private) + " ";
    cout << string_to_print << endl;
    return 0;
}