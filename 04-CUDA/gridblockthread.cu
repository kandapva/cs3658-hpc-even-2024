#include <stdio.h>
#include <cuda.h>
__global__ void dkernel(unsigned *nthreads) {
	if (threadIdx.x == 0 && blockIdx.x == 0 && threadIdx.y == 0 && blockIdx.y == 0 && threadIdx.z == 0 && blockIdx.z == 0) {
	//if (threadIdx.x == 0) {
    		printf("%d %d %d %d %d %d.\n", gridDim.x, gridDim.y, gridDim.z, blockDim.x, blockDim.y, blockDim.z);
	}
	atomicInc(nthreads, 1000000);
}
int main() {
	dim3 grid(2, 3, 4);
	dim3 block(5, 6, 7);
	unsigned *nthreads, hnthreads = 0;
	cudaMalloc(&nthreads, sizeof(unsigned));
	cudaMemcpy(nthreads, &hnthreads, sizeof(unsigned), cudaMemcpyHostToDevice);
    dkernel<<<grid, block>>>(nthreads);
	cudaMemcpy(&hnthreads, nthreads, sizeof(unsigned), cudaMemcpyDeviceToHost);
	printf("%d\n", hnthreads);
    return 0;
}
