#include <stdio.h>
#include <malloc.h>
int n, g[10][10], v[10];
int main()
{
    int in, td = 0, indegree = 0, outdegree = 0, n, i, j;
    printf("\nEnter total number of vertices:");
    scanf("%d", &n);
    printf("\nThe Entries of Adjacency Matrix of The Graph Are\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\nEnter the entry of adjacency matrix of the graph at row %d and column %d:\t", i + 1, j + 1);
            scanf("%d", &g[i][j]);
        }
    }
    printf("\nEnter the entries of the vector v\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", g[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the vertex to find indegree:");
    scanf("%d", &in);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == in - 1 && g[i][j] == 1)
            {
                indegree++;
            }
        }
    }
    printf("Node=%d\t indegree=%d", in, indegree);
}