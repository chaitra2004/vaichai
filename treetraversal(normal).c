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
struct node *deletenode(struct node *root,int key)
{
  if(root==NULL)
    {
        return root;
    }
    if(key <root->data)
    {
        root->left = deletenode(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = deletenode(root->right,key);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
           struct node *temp = root->left;
           free(root);
           return temp;
        }
    }
    print2D(root);
    return root;
}
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
int postorder(struct node *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d\t", root->data);
}
}
int preorder(struct node *root)
{
if (root != NULL)
{
printf("%d\t", root->data);
preorder(root->left);
preorder(root->right);
}
}
int inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d\t", root->data);
inorder(root->right);
}
}
int main()
{
    struct node *root=newnode(41);
    root->left=newnode(21);
    root->right=newnode(16);
    root->left->left=newnode(18);
    root->left->right=newnode(19);
    root->right->left=newnode(12);
    root->right->right=newnode(14);
    print2D(root);
    printf("post order traversal of given tree\n");
    postorder(root);
    printf("\npre order traversal of given tree\n");
    preorder(root);
    printf("\nin order traversal of given tree\n");
    inorder(root);
    deletenode(root,18);
    return ;
}
