#include<stdio.h>
//using namespace std;
 
struct Node
{
    int key;
    struct Node *left, *right;
};
 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL)  return ;
 
    if (root->key == key)
    {
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
 
Node* newNode(int item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
Node* insert(Node* node, int key)
{
    if (node == NULL) 
		return newNode(key);
    if (key < node->key)
        node->left=insert(node->left, key);
    else
        node->right=insert(node->right, key);
    return node;
}
 
int main()
{
    int key,n,num,i=1;
    Node *root = NULL;
    printf("Enter the number of element:");
    scanf("%d",&n);
    scanf("%d",&num);
    root=insert(root,num);
    while(i<n)
    {
    	scanf("%d",&num);
    	insert(root,num);
    	i++;
    }
 	printf("Enter the element to seach for predeccessor and sucessor\n");
 	scanf("%d",&key);
    Node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
     printf("Predecessor is %d\n",pre->key);
    else
      printf("No Predecessor");
 
    if (suc != NULL)
      printf("Successor is %d\n",suc->key);
    else
      printf("No Successor");
    return 0;
}
