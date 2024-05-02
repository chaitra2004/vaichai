#include<stdio.h>
struct node
{
struct node *left, *right;
int key;
};
struct node *newNode(int item);
int preorder(struct node *root);
struct node *insert(struct node *node, int key);
struct node *minValueNode(struct node *node);
int main()
{
//system("cls");
struct node *root = NULL;
root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 20);
root = insert(root, 40);
root = insert(root, 70);
root = insert(root, 60);
root = insert(root, 80);
printf("pre order traversal of given tree \n");
preorder(root);
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
int preorder(struct node *root)
{
if (root != NULL)
{
printf("%d\t", root->key);
preorder(root->left);
preorder(root->right);
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
struct node *minValueNode(struct node *node)
{
struct node *current = node;
while (current->left != NULL)
{
current=current->left;
}
return current;
}

