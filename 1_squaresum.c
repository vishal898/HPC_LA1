// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include <time.h>



int main()
{
	double time_spent = 0.0;

	clock_t begin = clock();


	long long sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		long long z = i * i;
		printf("square %d:%lld ", i, z);
		sum += z;
	}
	printf("\n");
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds", time_spent);
}
