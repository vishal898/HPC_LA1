#include <omp.h>
#include <stdio.h>

void main()
{
    printf("Adding Two Arrays\n");
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {11, 12, 13, 14, 15};
    int a3[5] = {0};

    #pragma omp parallel for reduction(+ : a3)
    for (int i = 0; i < 5; i++)
    {
        a3[i] = a1[i] + a2[i];
    }


    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a3[i]);
    }
}