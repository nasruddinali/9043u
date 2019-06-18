#include <stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data) 
{
  struct node* node=(struct node*)malloc(sizeof(struct node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
   
  return(node);
}
 
struct node* insert(struct node* node, int data) 
{
  if (node==NULL) 
    return(newNode(data));  
  else
  {
    if (data <= node->data) 
        node->left=insert(node->left,data);
    else
        node->right=insert(node->right,data);
   
    return node; 
  }
}
 
int min(struct node* node) 
{
  struct node* current=node;
 
  while (current->left!=NULL) 
  {
    current=current->left;
  }
  return current->data;
}
 
int max(struct node* node) 
{
  struct node* current=node;
 
  while (current->right!=NULL) 
  {
    current=current->right;
  }
  return current->data;
} 
 
int main()
{
	int n,i=1,num;
  	struct node* root=NULL;
  	printf("Enter number of elements:");
  	scanf("%d",&n);
  	printf("Enter the elements:\n");
  	scanf("%d",&num);
  	root=insert(root,num);
  	while(i<n)
  	{
  		scanf("%d",&num);
  		insert(root,num);
  		i++;
  	}  
 
	printf("\nMinimum and Maximum value in BST is %d and %d", min(root),max(root));
 	return 0;    
}
