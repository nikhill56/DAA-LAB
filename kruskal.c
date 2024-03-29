#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int a, b, n, u, v,ne = 1;
int min, mincost = 0;
int cost[20][20],parent[20];

int find(int);
int uni(int, int);

int main()
{
	int i, j;
	printf("Enter number of vertices:");
	scanf("%d", &n);

	printf("\nEnter cost adjacency matrix:\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);

			if (cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}

	while (ne < n)
	{
		for (i = 1, min = 999; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (cost[i][j] < min)
				{
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}

		}

		u=find(u);
		v=find(v);

		if (uni(u, v))
		{
			printf("\n%d edge:(%d->%d)=%d", ne++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = 999;


	}

	printf("\nMinimum cost is:%d", mincost);

}

int find(int i)
{	
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i, int j)
{
	if (i != j)
	{	
		parent[j]=i;
		return 1;
	}
	return 0;
}