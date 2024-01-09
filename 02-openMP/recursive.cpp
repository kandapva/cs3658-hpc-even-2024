#include <iostream>
#include <omp.h>

using namespace std;

size_t fib_omp(size_t n) {
      size_t right, left;
      if (n<2)
        return n;
      else {
        #pragma omp task shared(right)
            right = fib_omp(n-1);
        #pragma omp task shared(left)
            left = fib_omp(n-2);
        #pragma omp taskwait
            return right + left;
      }
}

size_t fib(size_t n)
{
    size_t right, left;
    if (n < 2)
        return n;
    else 
        return fib_omp(n - 1) + fib_omp(n - 2);
}

int main()
{
    size_t x, fib_ans;
    x = 20;
    #pragma omp parallel shared(x,fib_ans)
    {
        #pragma omp single
            fib_ans = fib_omp(x);
    }
    cout << "Sum of Nth fib seqquence is (omp) " << fib_ans << endl;
    cout << "Sum of Nth fib seqquence is (rec) " << fib(x) <<endl;

    return 0;
}