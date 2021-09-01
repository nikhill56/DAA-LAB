#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void main()
{
    int x = 0;
    int count = 0;
    double clk;
    double starttime, endtime;

    int a[MAX], i, j, n;

    printf("Enter size:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        scanf("%d",&a[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    starttime = clock();

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                
            }
            
        }
        
    }

    endtime = clock();
    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nThe runtime is %lfms,%d\n", (endtime - starttime) / CLOCKS_PER_SEC,count);
}