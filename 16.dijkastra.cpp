#include <stdio.h>
#include <limits.h>

int V;
 
int minDistance(int dist[], bool sptSet[])
{
   int min=999,index;
 
   for(int v=0;v<V;v++)
     if(sptSet[v]==false && dist[v]<=min)
         min=dist[v],index=v;
 
   return index;
}
 
int printSolution(int dist[])
{
   printf("Vertex   Distance from Source\n");
   for(int i=0;i<V;i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
void dij(int graph[10][10], int src)
{
     int dist[V]; 
     bool sptSet[V];
     for(int i=0;i<V;i++)
        dist[i]=999, sptSet[i]=false;
 
     dist[src]=0;
 
     for(int count=0;count<V-1;count++)
     {
       	int u=minDistance(dist, sptSet);
    	sptSet[u]=true;
  	    for(int v=0;v<V;v++)
	       if(!sptSet[v] && graph[u][v] && dist[u]!=999 && dist[u]+graph[u][v] < dist[v])
            dist[v]=dist[u]+graph[u][v];
     }
 
     printSolution(dist);
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
	dij(graph,0);
    return 0;
}
