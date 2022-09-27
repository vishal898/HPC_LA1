#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 200;

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    int ans[n];
    int val = 5;

    double time_spent = 0.0;
    clock_t begin = clock();



    #pragma omp parallel
    {
        #pragma omp for nowait
        for (int i = 0; i < n; i++)
        {
            ans[i] = arr[i] + val;
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds\n", time_spent);


    printf("Output: \n");
    for (int i = 0; i < n; i++) {
        printf("\t %d", ans[i]);
    }

    return 0;
}