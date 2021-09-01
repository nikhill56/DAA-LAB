#include <stdio.h> //TRUE
#include <time.h>
#include <stdlib.h>
#define MAX 100000

void merge(int a[], int i1, int j1, int i2, int j2)
{   
    
    int temp[MAX];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;          //temp array
    while (i <= j1 && j <= j2)  //comparing two subarrays
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    /* Copy the remaining elements of first half, if there are any */
    while (i <= j1)
        temp[k++] = a[i++];
    /* Copy the remaining elements of second half, if there are any */
    while (j <= j2)
        temp[k++] = a[j++];

    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}
void mergesort(int a[], int i, int j)
{   
    
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;
        mergesort(a, i, mid);
        // recurcive mergesort first and second halves
        mergesort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}

int main()
{
    int a[MAX], n, i;
    float clocktime;
    double startime, endtime;

    printf("Enter no of Employee ID's:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        a[i] = rand() % 10;

    printf("\nUnsorted Employee ID's:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    startime = clock();

    mergesort(a, 0, n - 1);

    endtime = clock();
    clocktime = (float)((endtime - startime) / CLOCKS_PER_SEC);
    printf("\n");
    printf("\nSorted Employee ID's are :\n");
    for (i = 0; i < n; i++)
        printf("%d \t", a[i]);

    printf("\nTime taken for execution %f ms\n", clocktime);
    
    return 0;
    
}
