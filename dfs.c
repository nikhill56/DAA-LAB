#include <stdio.h> //TRUE
#include <stdlib.h>
#include <time.h>
int DepthFirstSearch(int);

const int n;

int graph[20][20], visited[10];

int DepthFirstSearch(int x)
{
    int i;

    printf("%d->", x);

    visited[x] = 1;

    for (i = 0; i < n; i++)
    {

        if (visited[i] == 0 && graph[x][i] == 1)
        {
            DepthFirstSearch(i);
        }
    }

    return 0;
}

int main()
{
    float clocktime;
    double starttime, endtime;

    int i, j, x;

    printf("\n enter number of vertices:");

    scanf("%d", &n);

    printf("\n enter adjecency matrix :\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n enter starting vertice:");
    scanf("%d", &x);

    printf("Depth First Search is\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    starttime = clock();
    DepthFirstSearch(x);
    endtime = clock();
    clocktime = (float)((endtime - starttime) / CLOCKS_PER_SEC);
    printf("\nTime taken for execution %f ms\n", clocktime);

    return 0;
}