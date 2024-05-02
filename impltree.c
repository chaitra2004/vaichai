#include<stdio.h>
#define count 10
struct node{
int data;
struct node *left,*right;
};
struct node *newnode(int data)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->right=node->left=NULL;
    return node;
};
void print2DUtil(struct node *root,int space)
{
    int i;
    if(root==NULL)
        return;
    space+=count;
    print2DUtil(root->right,space);
    printf("\n");
    for(i=count;i<space;i++)
        printf(" ");
    printf("%d\n",root->data);
    print2DUtil(root->left,space);
}
void print2D(struct node *root)
{
    print2DUtil(root,0);
}
int main()
{
    struct node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    root->left->left->left=newnode(8);
    root->left->left->right=newnode(9);
    root->left->right->left=newnode(10);
    root->left->right->right=newnode(11);
    root->right->left->left=newnode(12);
    root->right->left->right=newnode(13);
    root->right->right->left=newnode(14);
    root->right->right->right=newnode(15);
    print2D(root);
    return 0;
}
