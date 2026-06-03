#include <stdio.h>

#define INF 9999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter the cost adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n];
    int visited[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n - 1; count++)
    {
        int min = INF;
        int nextNode = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] &&
               min + cost[nextNode][i] < dist[i])
            {
                dist[i] = min + cost[nextNode][i];
            }
        }
    }

    printf("\nShortest Distances from Vertex %d:\n", source);

    for(int i = 0; i < n; i++)
    {
        printf("To Vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}
