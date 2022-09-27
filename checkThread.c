// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>



int main()
{
	int nthreads, tid;

	double time_spent = 0.0;

	clock_t begin = clock();
	// Begin of parallel region
	#pragma omp parallel private(nthreads, tid)
	{
		// Getting thread number
		tid = omp_get_thread_num();
		printf("Hello world = %d\n", tid);

		if (tid == 0) {

			// Only master thread does this
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n",
			       nthreads);
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds", time_spent);
}
