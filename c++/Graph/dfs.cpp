#include<bits/stdc++.h>
using namespace std;

void dfs_traversal(int start,vector<int>& visited,vector<int> adj[],vector<int> &ans){
    visited[start]=1;
    ans.push_back(start);
    int size=adj[start].size();
    for(int i=0;i<size;i++){
        if(visited[adj[start][i]]==0){
            dfs_traversal(adj[start][i],visited,adj,ans);
        }
    }
    return ;
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
    vector<int> visited(n+1,0);
    vector<int> ans;
    dfs_traversal(1,visited,adj,ans);
    for(auto it : ans){
        cout<<it<<endl;
    }

    // if we have weighted graph then 
    // we can store pair in case of int 
}
