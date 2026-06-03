#include <stdio.h>

#define MAX 20

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter cost adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    int mincost = 0;
    int edges = 0;

    printf("\nEdges in Minimum Cost Spanning Tree:\n");

    while(edges < n - 1)
    {
        int min = 999;
        int a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if(u != v)
        {
            printf("%d --> %d  Cost = %d\n", a, b, min);

            mincost += min;
            unionSet(u, v);
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}
