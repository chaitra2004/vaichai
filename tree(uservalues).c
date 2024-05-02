#include<stdio.h>
#define count 10
struct node
{
struct node *left, *right;
int key;
};
struct node *newNode(int item);
int inorder(struct node *root);
struct node *insert(struct node *node, int key);
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
    printf("%d\n",root->key);
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
printf("%d\t", root->key);
}
}
int preorder(struct node *root)
{
if (root != NULL)
{
printf("%d\t", root->key);
preorder(root->left);
preorder(root->right);
}
}
int main()
{
//system("cls");
struct node *root = NULL;
int n,data,i;
printf("enter the number of nodes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("enter the data\n");
    scanf("%d",&data);
    root=insert(root,data);
}
print2D(root);
printf("in order traversal of given tree \n");
inorder(root);
printf("\npre order traversal of given tree \n");
preorder(root);
printf("\npost order traversal of given tree \n");
postorder(root);

return 0;
}
// create new BST tree
struct node *newNode(int item)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
int inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);
printf("%d\t", root->key);
inorder(root->right);
}
}
struct node *insert(struct node *node, int key)
{
if (node == NULL)
return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else
node->right = insert(node->right, key);
return node;
}
