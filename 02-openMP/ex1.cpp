#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <cmath>

void display(float *a, int N){
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		std::cout << a[i] << "\t";
	std::cout << std::endl;
}

//  Exercise 1 - Applying ReLU activation function to vector
int main(int argc,char **argv)
{

	int  thread_id, num_threads;
	int N = pow(2,atoi(argv[1]));
	omp_set_num_threads(8);

	float *input_array, *output_array;
	// creating memory for array of size N
	input_array = (float *)malloc(sizeof(float) * N);
	output_array = (float *)malloc(sizeof(float) * N);
	std::cout << "Vector size is " << N << std::endl;
	// Initialize Input vector
	for (int i = 0; i < N; i++)
		input_array[i] = pow(-1, i) * i;

	// Serial code for ReLU
	double start = omp_get_wtime();
	#pragma omp parallel num_threads (1)
	for (int i = 0; i < N; i++)
	{
		if(input_array[i] < 0.0)
			output_array[i] = 0.0;
		else
			output_array[i] = input_array[i];
	}
	double end = omp_get_wtime() - start;
	std::cout << "Serial time - " << end << "s" << std::endl;
	omp_set_num_threads(8);
	// Reinitialize for method 1
	for (int i = 0; i < N; i++)
		input_array[i] = pow(-1, i) * i;

	// Parallel Method 1: 
	start = omp_get_wtime();
	#pragma omp parallel for shared (input_array,output_array)
	for (int i = 0; i < N; i++)
	{
		if (input_array[i] < 0.0)
			output_array[i] = 0.0;
		else
			output_array[i] = input_array[i];
	}
	end = omp_get_wtime() - start;
	std::cout << "Method 1 time - " << end << "s" << std::endl;
	omp_set_num_threads(8);

	// Parallel Method 2:
	start = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		if (input_array[i] < 0.0)
			output_array[i] = 0.0;
		else
			output_array[i] = input_array[i];
	}
	end = omp_get_wtime() - start;
	std::cout << "Method 2 time - " << end << "s" << std::endl;

	if(N<20){
		display(input_array,N);
		display(output_array, N);
	}

	// Method 3
	int nt = omp_get_num_threads(); // $$
	// std::cout<<nt;
	int chunk = N/nt;
	start = omp_get_wtime();
#pragma omp parallel num_threads (nt)
	{
		int start_index = omp_get_thread_num()*chunk;
		(omp_get_thread_num() == 7) ? chunk = N / nt + N % nt : chunk = N / nt;
		for (int i = start_index; i < start_index+chunk; i++)
		{
			if (input_array[i] < 0.0)
				output_array[i] = 0.0;
			else
				output_array[i] = input_array[i];
		}
	}
	end = omp_get_wtime() - start;
	std::cout << "Method 3 time - " << end << "s" << std::endl;

	free(input_array);
	free(output_array);

	return 0;
}