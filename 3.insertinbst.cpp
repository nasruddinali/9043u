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
	else if(num >= root->data)
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

int main()
{
	int num,i=0,n;
	char ans;
	printf("Enter the number of elements you want to enter:");
	scanf("%d",&n);
	while(i<n)
	{
		printf("\n");
		scanf("%d",&num);
		root=insert(root,num);
		inorder(root);
		i++;
	}
	return 0;
}
