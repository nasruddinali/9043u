#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
 
int max(int a, int b);
 
int height(struct node *N)
{
    if (N==NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    if(a > b)
    	return a;
    else 
		return b;	
}
 
struct node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return(node);
}
 
struct node *rightRotate(struct node *y)
{
    struct node *x=y->left;
    struct node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left), height(y->right))+1;
    x->height=max(height(x->left), height(x->right))+1;
    return x;
}
 
struct node *leftRotate(struct node *x)
{
    struct node *y=x->right;
    struct node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left), height(y->right))+1;
    return y;
}
 
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left)-height(N->right);
}
 
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left=insert(node->left, key);
    else
        node->right=insert(node->right, key);
 
    node->height=max(height(node->left), height(node->right)) + 1;
 
    int balance=getBalance(node);
 	
	if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    if (balance > 1 && key > node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
void preOrder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main()
{
  int n,num,i=0;
  struct node *root=NULL;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  while(i<n)
  {
  	scanf("%d",&num);
  	root=insert(root,num);
  	i++;
  }
  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);
 
  return 0;
}
