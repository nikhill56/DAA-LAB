#include <stdio.h>
#include <time.h>

int a[10][10], visited[10], n, cost = 0;

void mincost(int city)

{

    int i, ncity;

    visited[city] = 1; //mark as visted

    printf("%d-->", city + 1);

    ncity = least(city);

    if (ncity == 999)

    {

        ncity = 0;

        printf("%d", ncity + 1);

        cost += a[city][ncity];

        return;
    }

    mincost(ncity);
}

int least(int city)

{

    int i, nc = 999;

    int min = 999;

    for (i = 0; i < n; i++)

    {

        if ((a[city][i] != 0) && (visited[i] == 0))

            if (a[city][i] < min)

            {

                min = a[city][i];

                nc = i;
            }
    }

    if (min != 999)

        cost += min;

    return nc;
}

void main()

{

    int i, j;

    double clk;

    clock_t starttime, endtime;

    printf("enter the number of cities\n");

    scanf("%d", &n);

    printf("enter the cost matrix\n");

    for (i = 0; i < n; i++)

    {

        printf("enter the rows elements# :%d\n", i + 1);

        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    printf("The cost matrix is\n");

    for (i = 0; i < n; i++)

    {

        printf("\n\n");

        for (j = 0; j < n; j++)

            printf("\t%d", a[i][j]);
    }

    printf("\nthe path is\n");

    starttime = clock();

    mincost(0);

    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nthe min cost is %d\n", cost);

    printf("the runtime is %f\n", clk);
}