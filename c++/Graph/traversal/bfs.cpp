#include<bits/stdc++.h>
using namespace std;

// time complexity is O(E)
// space complexity is O(n+n)
void bfs_traversal(int start,int n,undirected_map<int,vector<int>>&adj,vector<int>&ans,vector<int>&visited){
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int x=q.front();
       ans.push_back(x);
        q.pop();
        int size=adj[x].size();
        for(int i=0;i<size;i++){
            if(visited[adj[x][i]]==0){
            visited[adj[x][i]]=1;
            q.push(adj[x][i]);
            }
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
    undirected_map<int,vector<int>> adj;
    for(int i=0;i<m;i++){
        int v,u;
        cin>>v>>u;
        // for undirected graph 
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    // if graph is not connected then we have to pass ans as a refrence
    // and also visited 
    // in the BFS
    vector<int> ans;
    vector<int> visited(n+1,0);  
    for(int i=1;i<=n;i++){
        if(visited[i]==0)
        bfs_traversal(i,n,adj,ans,visited);
    }
    for(auto it : ans){
        cout<<it<<endl;
    }
    // if we have weighted graph then 
    // we can store pair in case of int 
}
