#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
}*root=NULL,*newnode;

node* insert(node* root,int num)
{
	if(root==NULL)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=num;
		newnode->left=NULL;
		newnode->right=NULL;
		root=newnode;
	}
	else if(num > root->data)
	{
		root->right=insert(root->right,num);
	}
	else if(num < root->data)
	{
		root->left=insert(root->left,num);
	}
	
	return root;
}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void preorder(node* root)
{
	if(root!=NULL)
	{
		printf("%d->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d->",root->data);
	}
}

int main()
{
	int num,i=0;
	char ans;
	printf("Enter 5 elements:\n");
	while(i<5)
	{
		scanf("%d",&num);
		root=insert(root,num);
		i++;
	}
	printf("\nInorder\n");
	inorder(root);
	printf("\nPreorder\n");
	preorder(root);
	printf("\nPostorder\n");
	postorder(root);
	return 0;
}
