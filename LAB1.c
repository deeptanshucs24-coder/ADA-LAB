#include <stdio.h>

#define MAX 100

int main()
{
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    int topo[MAX];
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");

    for(int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }

    while(front <= rear)
    {
        int u = queue[front++];
        topo[count++] = u;

        for(int v = 0; v < n; v++)
        {
            if(adj[u][v] == 1)
            {
                indegree[v]--;

                if(indegree[v] == 0)
                    queue[++rear] = v;
            }
        }
    }

    if(count != n)
    {
        printf("Topological ordering is not possible (Graph contains a cycle)\n");
    }
    else
    {
        printf("Topological Ordering:\n");

        for(int i = 0; i < n; i++)
        {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}
