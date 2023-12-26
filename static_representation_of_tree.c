/*#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    char data;
    struct node *right;
    struct node *left;
}node;
struct node* insert(char c[],int n)
{
    struct node *tree=NULL;
    if (c[n]!='\0')
    {
        tree=(struct node*)malloc(sizeof(struct node));
        tree->left=insert(c,2*n+1);
        tree->data=c[n];
        tree->right=insert(c,2*n+2);
    }
    return tree;
}
void inorder(struct node*tree)
{
    if (tree!=NULL)     
    {
        inorder(tree->left);
        printf("%c\t",tree->data);
        inorder(tree->right);
    }
}
void main()
{
    struct node*tree=NULL;
    char c[]={'A','B','C','D','E','F','\0','G','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    tree=insert(c,0);
    inorder(tree);
}
*/













































#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
}node;
struct node* insert(char c[],int n)
{
 struct node *tree=NULL;
 if (c[n]!='\0')
 {
    tree=(struct node *)malloc(sizeof(struct node));
    tree=insert(c,2*n+1);
    tree->data=c[n];
    tree=insert(c,2*n+2);
 }
 return tree;
}
void inorder(struct node *tree)
{
    if (tree!=NULL)
    {
        inorder(tree->left);
        printf("%c\t",tree->data);
        inorder(tree->right);
    }
}
void main()
{
    struct node *tree=NULL;
    char c[]={'A','B','C','D','E','F','\0','G','\0','\0','\0','\0','\0'};
    tree=insert(c,0);
    inorder(tree);
}