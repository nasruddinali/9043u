#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
	struct Node *left,*right;
}*head,*ptr,*temp,*root,*tree1,*tree2,*treetemp,*tempp;

void inorder(struct Node *trv)
{
	if(trv!=NULL)
	{
		inorder(trv->left);
		printf("%d\t",trv->data);
		inorder(trv->right);
	}
}

void sort()
{	
	int swap;
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr->link;
		while(temp!=NULL)
		{	
			if(ptr->data > temp->data)
			{
				swap=ptr->data;
				ptr->data=temp->data;
				temp->data=swap;
				
				tempp=ptr->left;
				ptr->left=temp->left;
				temp->left=tempp;
				
				tempp=ptr->right;
				ptr->right=temp->right;
				temp->right=tempp;
			}
			temp=temp->link;
		}
		ptr=ptr->link;
	}
}

struct Node* newNode(int item)
{
    temp->data=item;
    temp->left=NULL;
	temp->right=NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key)
{
    if (node==NULL) 
		return newNode(key);
    
	if (key < node->data)
        node->left=insert(node->left, key);
    else
        node->right=insert(node->right, key);
    
	return node;
}

int main()
{
	
	int n,num,i=0;
	head=NULL;
	root=NULL;
	printf("Enter the number of element:");
    scanf("%d",&n);
    temp=(struct Node *)malloc(sizeof(struct Node));
	while(i<n)
	{	
		scanf("%d",&num);
		temp->data=num;
		temp->link=NULL;
		temp->left=NULL;
		temp->right=NULL;
		if(head==NULL)
		{	
			head=temp;
			ptr=temp;
		}
		else
		{
			ptr->link=temp;
			ptr=temp;
		}
		temp=(struct Node *)malloc(sizeof(struct Node));
		i++;
	}
	free(temp);
	
	while(head->link!=NULL)
	{	
		sort();
		tree1=head;
		head=head->link;
		tree2=head;
		head=head->link;
		treetemp=(struct Node *)malloc(sizeof(struct Node));
		treetemp->data=tree1->data+tree2->data;
		treetemp->left=tree1;
		treetemp->right=tree2;
		root=treetemp;
		treetemp->link=head;
		head=treetemp;
	}
	printf("\nthe inorder traversal of huffman tree is :\n");
	inorder(root);
	return 0;
}
