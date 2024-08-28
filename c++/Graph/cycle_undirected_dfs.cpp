#include<bits/stdc++.h>
using namespace std;

bool dfs_traversal(int start,int parent,vector<int>& visited,vector<int> adj[]){
    visited[start]=1;
    int size=adj[start].size();
    for(int i=0;i<size;i++){
        if(visited[adj[start][i]]==0){
            bool b1=dfs_traversal(adj[start][i],start,visited,adj);
            if(b1==true){
                return true;
            }
        }else{
            if(parent!=adj[start][i]){
                return true;
            }
        }
    }
    return false;
}

bool detect_cycle(int n,vector<int> adj[]){
    vector<int> visited(n,0); 
    for(int i=0;i<n;i++){
       bool b1 =dfs_traversal(i,-1,visited,adj);
       if(b1==true){
        return true;
       }
    }
    return false;
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

    bool ans=detect_cycle(n,adj);
    cout<<ans<<endl;

    // if we have weighted graph then 
    // we can store pair in case of int 
}
