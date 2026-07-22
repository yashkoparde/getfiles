//Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal’s algorithm.
// #include <stdio.h>

#define MAX 100
#define INF 999

int parent[MAX], cost[MAX][MAX];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int a, int b)
{
    parent[find(b)] = find(a);
}

void kruskal(int n)
{
    int edges = 0, sum = 0;

    printf("\nEdges of spanning tree are:\n");

    while (edges < n - 1)
    {
        int min = INF, u = -1, v = -1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && cost[i][j] < min && find(i) != find(j))
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }

        if (u == -1)
            break;

        unite(u, v);
        printf("%d -> %d\n", u, v);
        sum += min;
        cost[u][v] = cost[v][u] = INF;
        edges++;
    }

    printf("Cost of spanning tree = %d\n", sum);
}

int main()
{
    int n;

    printf("Enter the n value: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    kruskal(n);
    return 0;
}