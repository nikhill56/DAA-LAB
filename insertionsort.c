#include <stdio.h> //TRUE
#include <stdlib.h>
#include <time.h>
#define MAX 100000
int main()
{

    int i, j, count, temp;

    double clocktime;
    double startime;
    double endtime;

    printf("How many numbers u are going to enter?: ");
    scanf("%d", &count);

    int number[MAX];

    for (i = 0; i < count; i++)
        number[i] = rand() % 1000;

    printf("\nUnsorted elements are:\n");

    for (i = 0; i < count; i++)
        printf("%d \t", number[i]);

    startime = clock();

    for (i = 1; i < count; i++)
    {
        temp = number[i];
        j = i - 1;
        while ((temp < number[j]) && (j >= 0))
        {
            number[j + 1] = number[j];
            j = j - 1;
        }
        number[j + 1] = temp;
    }
    endtime = clock();
    printf("\n\n");
    clocktime = (float)((endtime - startime) / CLOCKS_PER_SEC);

    printf("Order of Sorted elements: \n");
    for (i = 0; i < count; i++)
        printf("%d \t", number[i]);

    printf("\nTime taken for execution %f ms\n", clocktime);

    return 0;
}