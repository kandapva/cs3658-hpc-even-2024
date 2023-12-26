#include <iostream>
#include <chrono>

typedef struct{
    float a,b;
}cmplx;

typedef struct{
    float *a,*b;
}cmplx1;

int main(){
    int n;// Size of the array
    std::cin >> n;
    cmplx *A;
    A = (cmplx*)malloc(n*sizeof(cmplx));
    for(int i=0;i<n;i++){
        std::cin >> A[i].a >> A[i].b;
    }
    std::cout << "Array of Structures:" <<std::endl; 
    for(int i=0;i<n;i++){
        std::cout <<  A[i].a  << "+" <<  A[i].b << "i" << std::endl;
    }

    cmplx1 B;
    B.a = (float *)malloc(n * sizeof(float));
    B.b = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++)
    {
        std::cin >> B.a[i] >> B.b[i];
    }
    std::cout << "Structure of Arrays:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << B.a[i] << "+" << B.b[i] << "i" << std::endl;
    }
}