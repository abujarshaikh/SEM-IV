/*#include <stdio.h>
#include <stdlib.h>

// Define a structure for the BST node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with the given data
struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
/*
struct node *create()
{
    int n, x, i;
    struct node *root;
    root = NULL;
    printf("\n Enter no. of nodes\n");
    scanf("%d", &n);
    printf("\n Enter tree values :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    return root;
}*/
// Function to insert a node with the given data into the BST
/*struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a node with the given data in the BST
struct node *search(struct node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Function to display the nodes of the BST in order
void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// Function to count the number of nodes in the BST
int count(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count(root->left) + count(root->right);
    }
}

// Main function for testing the BST library functions
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST:\n");
    display(root);

    printf("\n\n");
    int search_value = 70;
    struct node *search_result = search(root, search_value);
    if (search_result == NULL)
    {
        printf("%d not found in the BST\n", search_value);
    }
    else
    {
        printf("%d found in the BST\n", search_result->data);
    }

    printf("\n");
    int node_count = count(root);
    printf("The number of nodes in the BST is %d\n", node_count);

    return 1;
}
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void create()
{
    root = NULL;
}

void insert()
{
    int value;
    printf("Enter the value to be inserted: ");
    scanf("%d", &value);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        struct node *current = root;
        struct node *parent;
        while (1)
        {
            parent = current;
            if (value < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newnode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newnode;
                    return;
                }
            }
        }
    }
}

void search()
{
    int value;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
    struct node *current = root;
    while (current->data != value)
    {
        if (current != NULL)
        {
            printf("Element found!\n");
            return;
        }
        if (current->data > value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    printf("Element not found!\n");
}

void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int count(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = count(root->left);
        int right_height = count(root->right);
        return (left_height + right_height + 1);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Create\n2. Insert\n3. Search\n4. Display\n5. Count\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            search();
            break;
        case 4:
            printf("The elements in the tree are: ");
            display(root);
            printf("\n");
            break;
        case 5:
            printf("The total number of nodes in the tree is %d.\n", count(root));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
