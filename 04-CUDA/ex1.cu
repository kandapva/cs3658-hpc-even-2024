#include <iostream>
#include <cuda.h>

#define N 1024

using namespace std;

__constant__ float filter[3] = {0.2,0.6,0.2};

__global__ void apply_filter(float *x, float *y){
    // Your code goes here
    int index = blockDim.x * blockIdx.x + threadIdx.x;
    if(index>0 && index<1023)
      y[index] += filter[0]*x[index-1] + filter[1]*x[index] + filter[2]*x[index+1];  
    // till here
}

int main(){
    float X_hs[N], *X_dev;
    float Y_hs[N], *Y_dev;

    // Initialise vector
    for(int i=0;i<N;i++){
        X_hs[i] = i * 1.0;
        Y_hs[i] = 0.0;
    }
    // Allocate memory in GPU (device)
    cudaMalloc(&X_dev, N * sizeof(float));
    cudaMalloc(&Y_dev, N * sizeof(float));

    // Transfer data to GPU
    cudaMemcpy(X_dev, X_hs, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(Y_dev, Y_hs, N * sizeof(float), cudaMemcpyHostToDevice);
    
    // Launch Kernel
     apply_filter<<<32,32>>>(X_dev, Y_dev);

    // Transfer data back to CPU
    cudaMemcpy(Y_hs, Y_dev, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Free memory in GPU
    for(int i=0;i<10;i++){
        cout << Y_hs[i] << endl;
    }
    cudaFree(X_hs);
    cudaFree(Y_hs);

    return 0;
}