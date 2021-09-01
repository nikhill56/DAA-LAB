#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    double clk;
    double starttime, endtime;

    int n, count = 0;
    int item, i, flag = 0;

    printf("Enter size:");
    scanf("%d", &n);

    int a[1000];
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    starttime = clock();
    printf("\nEnter Item which is to be searched\n");
    scanf("%d", &item);

    for (i = 0; i < 10; i++)
    {
        count++;
        if (a[i] == item)
        {
            flag = i + 1;
            break;
        }
    }
    endtime = clock();
    
    if (flag != 0)
    {
        printf("\nItem found at location %d\n", flag);
    }
    else
    {
        printf("\nItem not found\n");
    }

    printf("The count is:%d\n", count);
    printf("The runtime is %lfms\n", (endtime - starttime) / CLOCKS_PER_SEC);
}