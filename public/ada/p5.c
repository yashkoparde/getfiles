#include <stdio.h>
#include <stdlib.h>

void topologicalSort(int **graph, int indegree[], int n)
{
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    printf("\nTopological ordering is: ");

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u + 1);
        count++;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (count != n)
        printf("\nTopological ordering not possible");

    free(queue);
}

int main()
{
    int n;

    printf("Enter the n value: ");
    scanf("%d", &n);

    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        graph[i] = (int *)malloc(n * sizeof(int));

    int *indegree = (int *)calloc(n, sizeof(int));

    printf("Enter the graph data:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j])
                indegree[j]++;
        }
    }

    topologicalSort(graph, indegree, n);

    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(indegree);

    return 0;
}