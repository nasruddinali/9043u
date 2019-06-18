#include<stdio.h>
#include<stdlib.h>
 
 struct tree
 {
        int data;
        struct tree *left;
        struct tree *right;
        
 };
 
 struct q
 {
        struct q *next;
        struct tree * ptr;
 };


typedef struct tree node;


node* stack[15]={NULL},*root=NULL;

int top=-1;    
 
push(node* elem)
{                      
    stack[++top]=elem;
}
 
node* pop()
{   
     if(top==-1)
     {
                printf("\ninvalid postfix expression");
     } 
     else                               
    return(stack[top--]);
}


int isoperator(char elem)
{               
    switch(elem)
    {
    case '(':
    case '+':
    case '-': 
    case '*':
    case '/': return 1;
    default : return 0;
    }
}
    
void createtree(char input[],int size)
{
     int i=0;
     node *temp,*temp1,*temp2;
     
          while(input[i]!='\0')
            {                  
                      if(! isoperator(input[i]))
                      { 
						  temp=(node*)malloc(sizeof(node));
                          temp->data=input[i];
                          temp->left=NULL;
                          temp->right=NULL;
                          push(temp);
                              
                      }
                      else
                      {
                          temp2=pop();
                          temp1=pop();
                          temp=(node*)malloc(sizeof(node));
                          temp->data=input[i];
                          temp->left=temp1;
                          temp->right=temp2;
                          push(temp);
                      }
               i++;           
             }               
     
     root=pop();
}     
                     
                      
void inorder(node * ptr)
{
     if(ptr==NULL)
     return;
     inorder(ptr->left);
     printf(" %c",ptr->data);
     inorder(ptr->right);
}

int main ()
{
    int choice,i;
    char input[20];
    printf("Enter postfix expression :");
    i=0;
    scanf("%s",input);
    createtree(input,i);
    inorder(root);             
    return 0;          
}
        
