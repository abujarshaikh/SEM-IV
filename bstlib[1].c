//C program to implement functions using BST library
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*r;
    struct node*l;
};
#define newnode (struct node*)malloc(sizeof(struct node));
struct node*insert(struct node *,int);
struct node*create()
{
    int n,x,i;
    struct node*root;
    root=NULL;
    printf("\n Enter no. of nodes\n");
    scanf("%d",&n);
    printf("\n Enter tree values :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }
    return root;
}
struct node*insert(struct node*rt,int x)
{
    if(rt==NULL)
    {
        rt=newnode;
        rt->l=rt->r=NULL;
        return rt;
    }
    else if(x>rt->data)
    {
        rt->r=insert(rt->r,x);
        return rt;
    }
    else
    {
        rt->l=insert(rt->l,x);
        return rt;
    }
}
void inorder(struct node*tmp)
{
    if(tmp!=NULL)
    {
        inorder(tmp->l);
        printf("%d",tmp->data);
        inorder(tmp->r);
        
    }
}
void preorder(struct node*tmp)
{
    if(tmp!=NULL)
    {
        printf("%d",tmp->data);
        preorder(tmp->l);
        preorder(tmp->r);
    }
}
void postorder(struct node*tmp)
{
    if(tmp!=NULL)
    {
        postorder(tmp->l);
        postorder(tmp->r);
        printf("%d",tmp->data);
    }
}
struct node*search(struct node*tmp,int x)
{
    if(tmp==NULL)
    return NULL;
    if(tmp->data==x)
    return (tmp);
    if(x>tmp->data)
    return (search((tmp->r),x));
    else
    return (search((tmp->l),x));
}
int main()
{
    int no,y;
    struct node*rt;
    rt=create();
    printf("\n Inorder");
    inorder(rt);
    printf("\n Preorder");
    preorder(rt);
    printf("\n Postorder");
    postorder(rt);
    printf("\n Enter the element to insert :");
    scanf("%d",&no);
    rt=insert(rt,no);
    printf("\n Enter the element to search :");
    scanf("%d",&y);
    rt=search(rt,y);
    if(rt!=NULL)
    printf("\n Node is found in tree");
    else 
    printf("\n Node is not found in tree :");
    return 0;
}