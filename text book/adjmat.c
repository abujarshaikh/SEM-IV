#include <stdio.h>
#include <malloc.h>

#define MAX 100

void degree(int adj[MAX][MAX], int x, int n)
{
    int i, incount = 0, outcount = 0;
    for (i = 0; i < n; i++)
    {
        if (adj[x][i] == 1)
            outcount++;
        if (adj[i][x] == 1)
            incount++;
    }
    printf("The indegree of the node %d is %d\n", x, incount++);
    printf("The outdegree of the node %d is %d\n", x, outcount++);
}
int main()
{
    int adj[MAX][MAX], n, i, j;
    printf("Enter the total number of nodes in graph:: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter the edge from %d to %d :\n", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        degree(adj, i, n);
    }
    return 0;
}