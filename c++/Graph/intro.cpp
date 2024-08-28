#include<bits/stdc++.h>
using namespace std;

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

    // if we have weighted graph then 
    // we can store pair in case of int 
}
