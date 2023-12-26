#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *Create(struct node *, int);
void Inorder(struct node *);
void Preorder(struct node *);
void Postorder(struct node *);
int main()
{
    struct node *root = NULL;
    setbuf(stdout, NULL);
    int choice, item, n, i;
    printf("\n*** Binary Search Tree ***\n");
    printf("\n1. Creation of BST");
    printf("\n2. Traverse in Inorder");
    printf("\n3. Traverse in Preorder");
    printf("\n4. Traverse in Postorder");
    printf("\n5. Exit\n");
    while (1)
    {
        printf("\nEnter Your Choice :(1.Create 2.Inorder 3.Preorder 4.Postorder 5.Exit)\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            printf("Enter number of nodes:\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d", &item);
                root = Create(root, item);
            }
            break;
        case 2:
            Inorder(root);
            break;
        case 3:
            Preorder(root);
            break;
        case 4:
            Postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Choice !!\n");
        }
    }
    return 0;
}
struct node *Create(struct node *root, int item)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if (item < root->data)
            root->left = Create(root->left, item); // recursive function call
        else if (item > root->data)
            root->right = Create(root->right, item);
        else
            printf(" Duplicate Element is Not Allowed !!!");
        return (root);
    }
}
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left); // recursive function call..
        printf("%d ", root->data);
        Inorder(root->right);
    }
}
void Preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        Preorder(root->left); // recursive function call
        Preorder(root->right);
    }
}
void Postorder(struct node *root)
{
    if (root != NULL)
    {
        Postorder(root->left); // recursive function call
        Postorder(root->right);
        printf("%d ", root->data);
    }
}
