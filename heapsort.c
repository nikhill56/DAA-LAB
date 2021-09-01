#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    double clocktime;
    double startime, endtime;

    int n;
    printf("\nEnter size of array:");
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100) + 1;
    }
    startime = clock();
    heapSort(arr, n);
    endtime = clock();
    clocktime = (float)((endtime - startime) / CLOCKS_PER_SEC);
    printf("Sorted array is \n");
    printArray(arr, n);
    printf("\nTime taken for execution %f ms\n", clocktime);
}