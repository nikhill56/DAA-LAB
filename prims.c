#include <stdio.h>

int a, b, u, v, n, i, j, ne = 1;

int visited[10] = {0}, min, minadj = 0, adj[10][10];

void main()

{

    printf("\nEnter the number of nodes:");

    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");

    for (i = 1; i <= n; i++)

        for (j = 1; j <= n; j++)

        {

            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 0)

                adj[i][j] = 999;
        }

    visited[1] = 1;

    printf("\n");

    while (ne < n)

    {

        for (i = 1, min = 999; i <= n; i++)

            for (j = 1; j <= n; j++)

                if (adj[i][j] < min)

                    if (visited[i] != 0)

                    {

                        min = adj[i][j];

                        a = u = i;

                        b = v = j;
                    }

        if (visited[u] == 0 || visited[v] == 0)

        {

            printf("\n Edge %d:(%d %d) adj:%d", ne++, a, b, min);

            minadj += min;

            visited[b] = 1;
        }

        adj[a][b] = adj[b][a] = 999;
    }

    printf("\n Minimun adj=%d", minadj);
}

//  0 4 4 0 0 0
//  4 0 2 0 0 0
//  4 2 0 3 2 4
//  0 0 3 0 0 3
//  0 0 2 0 0 3
//  0 0 4 3 3 0

// 0 4 4 0 0 0
// 4 0 2 0 0 0
// 4 2 0 1 3 6
// 0 0 1 0 0 3
// 0 0 3 0 0 2
// 0 0 0 3 2 0