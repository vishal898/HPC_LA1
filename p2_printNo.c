// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>



int main(int argc, char* argv[])
{
	int nthreads, tid;

	double time_spent = 0.0;

	clock_t begin = clock();

//	Begin of parallel region
	#pragma omp parallel for


	for (int i = 0; i < 50; i++)
	{


		printf("%d Hello world\n", i);
	}



	// for (int i = 0; i < 50; i++)
	// {

	// 	printf("%d Hello world\n",i);
	// }


	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds", time_spent);
}
