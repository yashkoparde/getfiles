#include <stdio.h>
#include <stdlib.h>

#define INF 999999

void dijkstra(int **cost, int n, int source, int dist[])
{
    int *visited = (int *)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        dist[i] = cost[source][i];

    visited[source] = 1;
    dist[source] = 0;

    for (int i = 1; i < n; i++)
    {
        int min = INF;
        int u = -1;

        // Find the unvisited vertex with minimum distance
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break; // Remaining vertices are unreachable

        visited[u] = 1;

        // Update distances
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] &&
                cost[u][j] != INF &&
                dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    free(visited);
}

int main()
{
    int n, source;

    printf("Enter n value: ");
    scanf("%d", &n);

    int **cost = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        cost[i] = (int *)malloc((n + 1) * sizeof(int));

    int *dist = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter the graph data:\n");

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    dijkstra(cost, n, source, dist);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            printf("Shortest distance from %d to %d is INF\n", source, i);
        else
            printf("Shortest distance from %d to %d is %d\n", source, i, dist[i]);
    }

    for (int i = 0; i <= n; i++)
        free(cost[i]);

    free(cost);
    free(dist);

    return 0;
}