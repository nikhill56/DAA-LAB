#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
// quick sort sorting algorithm
int Partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e-1; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, (p - 1)); // recursive QS call for left partition
        QuickSort(arr, (p + 1), e); // recursive QS call for right partition
    }
}

int main()
{
    double clk;
    double starttime, endtime;

    int size = 0;
    printf("Enter Size of array: \n");
    scanf("%d", &size);
    int myarray[MAX];

    for (int i = 0; i < size; i++)
    {
        myarray[i] = rand() % 1000;
    }
    printf("\nBefore Sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", myarray[i]);
    }

    starttime = clock();
    QuickSort(myarray, 0, (size - 1)); // quick sort called
    endtime = clock();
    printf("\nAfter Sorting\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", myarray[i]);
    }
    clk = (float)((endtime - starttime) / CLOCKS_PER_SEC);
    printf("\nThe runtime is %lfms\n", (endtime - starttime) / CLOCKS_PER_SEC);
    return 0;
}