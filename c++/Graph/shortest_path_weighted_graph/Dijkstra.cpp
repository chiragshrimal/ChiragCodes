#include<bits/stdc++.h>
using namespace std;

// Dijkstra algorithm 
// time complexity will be O(v+)
// space compleixty is O()

vector<int> Dijkstra_algo(int src, vector<vector<int>>&adj,vector<vector<int>>&w){
    int n=adj.size();
    vector<int>dis(n,INT_MAX);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> miniHeap;
    minHeap.push({0,src});
    while(!minHeap.empty()){
        auto it =minHeap.top();
        minHeap.pop();
        int node=it.second;
        int node_dist=it.first;
        for(auto nbr : adj[node]){
            int pre_dist=dist[nbr];
            int new_dist=node_dist+w[node][nbr];
            if(new_dist<pre_dist){
                dist[nbr]=new_dist;
                minHeap.push({new_dist,nbr});
            }
        }
    }
    return dis;
}

int main(){
    int n;
    cin>>n;
}