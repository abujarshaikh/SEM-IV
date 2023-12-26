#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *,int);
void postorder(struct node *);
int main()
{
    struct node *root=NULL;
    setbuf(stdout,NULL);
    char ch;
    int item;
    root=NULL;
    do
    {
        printf("Enter the data for root node::");
        scanf("%d",&item);
        root=create(root,item);
        printf("Do you want more nodes::");
        scanf(" %c",&ch);
} while (ch=='y'||ch=='Y');
  printf("***BST CREATED***\n");  
}
struct node *create(struct node *root,int item)
{
    if (root==NULL)
    {
        root=(struct node *)malloc(sizeof(struct node));
        root->left=root->right=NULL;
        root->data=item;
        return root;
    }
    else{
        if (item<root->data)
        {
            printf("%d is inserted at left of %d\n",item,root->data);
            root->left=create(root->left,item);
        }
        else if (item>root->data)
        {
            printf("%d is inserted at right of %d\n",item,root->data);
            root->right=create(root->right,item);
        }
        else
        {
            printf("Duplicate Elements Are Not Allowed");
        }
        return (root);
    }
}
