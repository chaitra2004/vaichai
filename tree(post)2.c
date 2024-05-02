#include<stdio.h>
struct node
{
struct node *left, *right;
int key;
};
struct node *newNode(int item);
int postorder(struct node *root);
struct node *insert(struct node *node, int key);
int main()
{
//system("cls");
struct node *root = NULL;
root = insert(root, 45);
root = insert(root, 32);
root = insert(root, 68);
root = insert(root, 92);
root = insert(root, 14);
root = insert(root, 12);
root = insert(root, 16);
root = insert(root, 40);
printf("post order traversal of given tree \n");
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
int postorder(struct node *root)
{
if (root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d\t", root->key);
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
