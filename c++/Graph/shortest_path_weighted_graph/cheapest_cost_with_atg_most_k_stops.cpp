#include<bits/stdc++.h>
using namespace std ;

// using BFS + Dijkstra algorithm 
// time complexity is O()
// space complexity is O()

int cheapest_cost(vector<vector<pair<int,int>>>&adj,int k,int src,int dest){
    int n=adj.size();
    // for price 
    vector<int>dist(n,INT_MAX);
    queue<vector<int>>q;
    q.push({-1,src,0});
    dist[src]=0;
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        int node=f[1];
        int price=f[2];
        int k_val=f[0];
        if(k_val>=k){
            continue;
        }
        for(auto nbr : adj[node]){
            int nbr_price=nbr.second;
            int nbr_node=nbr.first;
            if(nbr_price+price<dist[nbr_node]){
                dist[nbr_node]=nbr_price+price;
                q.push({k_val+1,nbr_node,dist[nbr_node]});
            }
        }
    }
    if(dist[dest]==INT_MAX){
        cout<<-1<<endl;
        return ;
    }
    cout<<dist[dest]<<endl;
    return ;

}



int main(){

}