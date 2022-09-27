#include<stdio.h>
#include <omp.h>


int fib(int n)

{

	if (n == 1 || n == 0)
		return n;
	else
	{
		int i, j;

		#pragma omp task shared(i) firstprivate(n)
		i = fib(n - 1);

		#pragma omp task shared(j) firstprivate(n)
		j = fib(n - 2);

		#pragma omp taskwait
		return i + j;
	}
}

int main ()
{
	int n = 5;
	#pragma omp parallel shared(n)
	{
		#pragma omp single
		printf("\n%d", fib(n));
	}

	return 0;
}