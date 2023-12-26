// Write a C program that accepts the vertices and edges of a graph. Create adjacency list.
#include <stdio.h>
#include <stdlib.h>
#define new_node (struct node *)malloc(sizeof(struct node))
struct node
{
    int vertex;
    struct node *next;
};
void main()
{
    int choice;
    do
    {
        printf("A Progrsm for the Representation of  graph using adjacency list");
        printf("\n 1.undirected Graph");
        printf("\n 2.Directed Graph");
        printf("\n 3.Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            undir_graph();
            break;
        case 2:
            dir_graph();
            break;
        case 3:
            exit(0);
        }
    } while (1);
}
int dir_graph()
{
    struct node *adj_list[10], *p;
    int n;
    int in_deg, out_deg, i, j;
    printf("How many Vertices do you want ?: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        adj_list[i] == NULL;
        // read_graph(adj_list, n);
        printf("\n Vertex \t In Degree \t Out Degree \t ,Total ");
    }
    for (i = 1; i <= n; i++)
    {
        in_deg = out_deg = 0;
        p = adj_list[i];
        while (p != NULL)
        {
            out_deg++;
            p = p->next;
        }
        for (j = 1; j <= n; j++)
        {
            p = adj_list[j];
            while (p != NULL)
            {
                in_deg++;
                p = p->next;
            }
        }
        printf("\n\n%5d\t\t\t%d\t\t%d\t\t%d\n\n", in_deg, out_deg, in_deg + out_deg);
    }
    return;
}
int undir_graph()
{
    struct node *adj_list[10], *p;
    int i, j, n, deg;
    printf("How many Vertices do you want ?: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        adj_list[i] == NULL;
    // read_graph(adj_list,n);
    printf("\n\n vertex\t\tdegree");
    for (i = 1; i <= n; i++)
    {
        deg = 0;
        p = adj_list[i];
        while (p != NULL)
        {
            deg++;
            p = p->next;
        }
        printf("\n\n%d\t\t%d", i, deg);
    }
    return 0;
}
int read_graph(struct node *adj_list[10], int n)
{
    int i, j;
    char reply;
    struct node *p, *c;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            printf("\n Vertices %d and %d are adjacent ? (Y/N):", i, j);
            scanf("%d", &reply);
            if (reply == 'Y' && reply == 'y')
            {
                c = new_node;
                c->vertex = j;
                c->next = NULL;
                if (adj_list == NULL)
                {
                    adj_list = c;
                }
                else
                {
                    p = adj_list[i];
                    while (p->next != NULL)
                    {
                        p = p->next;
                        p->next = c;
                    }
                }
            }
        }
    }
    return;
}