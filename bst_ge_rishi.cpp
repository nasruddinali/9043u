#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;
vector<bool> v(100,false);
void solveagain(vector< vector<int>> a,int s, int d);
void solution(vector< vector<int>> a,int maxValue,int s, int d)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            if(a[i][j]>maxValue)
                a[i][j]=0;
        }
    }
    solveagain(a,s,d);
    
}

void solveagain(vector< vector<int>> a,int s, int d)
{
    queue<int> q; 
    q.push(s);
    v[s]=true;
    
    while(!q.empty())
    {
        int f = q.front(); 
        q.pop(); 
        for (auto i = a[f].begin(); i != a[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
                if(*i==d)
                return;
            } 
        } 
        
    }
    
}


int main()
{
    int x,y,z;
    int n,q;
    
    cin >>n>>q;
    vector<vector<int>> arr(n,vector<int>(n,0)); 
    for(int i=0;i<n-1;i++)
        {
            cin >> x>>y>>z;
            arr[x-1][y-1] = z;
        }
     
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<n;j++)
            v[j]=false;
            vector<vector<int>> copy(n,vector<int>(n)); 
    
        // vector<vector<int>> copy = arr;
        // copy = arr;
        
        for (int u = 0;u<n;u++){
            for (int z=0;z<n;z++){
               copy[u][z] = arr[u][z]; 
            }
        }
        int maxValue,s,d;
        cin >>maxValue>>s>>d;
        solution(copy,maxValue,s-1,d-1);
        if(!v[d-1])
            cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    
}
