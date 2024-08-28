#include<bits/stdc++.h>
using namespace std;

vector<int> bfs_traversal(int start,int n,vector<int>arr[]){
    vector<int> ans;
    vector<int> visited(n+1,0);
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int x=q.front();
       ans.push_back(x);
        q.pop();
        int size=arr[x].size();
        for(int i=0;i<size;i++){
            if(visited[arr[x][i]]==0){
            visited[arr[x][i]]=1;
            q.push(arr[x][i]);
            }
        }
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    // methord 1
    // using matrix
    // int adj[n+1][n+1];
    // for(int i=0;i<m;i++){
    //     int v,u;
    //     cin>>v>>u;
    //     // for undirected graph dono trfh se connectivity hogi 
    //     adj[v][u]=1;
    //     abd[v][u]=1;
    // }

    // methord 2

    // using vector of list 

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int v,u;
        cin>>v>>u;
        // for undirected graph 
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    vector<int> ans=bfs_traversal(1,n,adj);
    for(auto it : ans){
        cout<<it<<endl;
    }

    // if we have weighted graph then 
    // we can store pair in case of int 
}
