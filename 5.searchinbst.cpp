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

node* search(node* root,int key)
{
	if(root==NULL || root->data==key)
	{
		return root;
	}
	if(root->data < key)
	{
		return search(root->right,key);
	}
	return search(root->left,key);
}

int main()
{
	int num,i=0,n,key,ans;
	printf("Enter the number of elements you want to enter:");
	scanf("%d",&n);
	scanf("%d",&num);
	root=insert(root,num);
	inorder(root);
	while(i<n)
	{
		printf("\n");
		scanf("%d",&num);
		insert(root,num);
		inorder(root);
		i++;
	}
	printf("Enter the number you want to :");
	scanf("%d",&key);
	root=search(root,key);
	printf("%d",root->data);
	return 0;
}
