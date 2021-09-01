#include <stdio.h> //TRUE
#include <stdlib.h>
#include <time.h>
#define MAX 100000
void main()
{
    long int n;
    int i, j, temp;
    float clocktime;
    double startime, endtime;

    int a[MAX];

    printf("\nEnter size of array:");
    scanf("%ld", &n);

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }

    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((temp < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int low, mid, high, key;
    
    printf("\nEnter value to search:");
    scanf("%d", &key);
    low = 0;
    high = n - 1;

    mid = (low + high) / 2;
    startime = clock();

    while (low <= high)
    {
        if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] > key)
            high = mid - 1;
        else
        {
            printf("\n%d found at location %d", key, mid + 1);
            break;
        }

        mid = (low + high) / 2;
    }
    endtime = clock();
    clocktime = (float)((endtime - startime) / CLOCKS_PER_SEC);

    if (low > high)
        printf("\nNot found! %d isn't present in the list", key);

    printf("\nTime taken for execution %f ms\n", clocktime);
}
