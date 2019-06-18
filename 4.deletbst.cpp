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

node* minnode(node* root)
{
	node* cur=root;
	while(cur->left!=NULL)
	{
		cur=cur->left;
	}
	
	return cur;
}

node* deletenode(node* root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	
	if(key > root->data)
	{
		root->right=deletenode(root->right,key);
	}
	else if(key < root->data)
	{
		root->left=deletenode(root->left,key);
	}
	else
	{
		if(root->left==NULL)
		{
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root->left;
			free(root);
			return temp;
		}
		node *temp=minnode(root->right);
		root->data=temp->data;
		root->right=deletenode(root->right,temp->data);
	}
	return root;
}

int main()
{
	int num,i=1,n,key,ans;
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
a:	printf("\nWant to delete(1 for YES otherwise NO):");
	scanf("%d",&ans);
	if(ans==1)
	{
		printf("Enter the number :");
		scanf("%d",&key);
		root=deletenode(root,key);
		inorder(root);
		goto a;
	}
	return 0;
}
