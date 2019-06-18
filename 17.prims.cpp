#include <stdio.h>
#include <limits.h>

int V;
 
int minKey(int key[], bool mstSet[])
{
   int min=999,index;
 
   for(int v=0;v<V;v++)
     if (mstSet[v]==false && key[v]<min)
         min=key[v],index=v;
 
   return index;
}
 
int printMST(int parent[],int graph[10][10])
{
   printf("Edge   Weight\n");
   for(int i=1;i<V;i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
void primMST(int graph[10][10])
{
     int parent[V]; 
     int key[V];   
     bool mstSet[V];
 
     for(int i=0;i<V;i++)
        key[i]=999,mstSet[i]=false;
 
     key[0] = 0;
     parent[0] = -1; 
 
     for(int count=0;count<V-1;count++)
     {
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++)
          if(graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]=u, key[v]=graph[u][v];
     }
 
    printMST(parent,graph);
}
 
 
int main()
{
   	int graph[10][10],i,j;
   	printf("Enter the number of vertices:");
   	scanf("%d",&V);
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
			if(i==j)
			{
				graph[i][j]=999;
			}
		}
	}
	 
    primMST(graph);
 
    return 0;
}
