#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    // methord 1
    // using matrix
    // vector<vector<int>> adj(n,vetor<int>(m,0));
    // for(int i=0;i<m;i++){
    //     int v,u;
    //     cin>>v>>u;
    //     // for undirected graph dono trfh se connectivity hogi 
    //     adj[v][u]=1;
    //     abd[v][u]=1;
    // }

    // methord 2

    // using vector of list 
    // yhe pe hum char or string wgr ka bhi use kar skte hai 
    // undirected_map<int,vector<int>> m;
    // undirected_map<string ,vector<string>> m;
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
