#include<bits/stdc++.h>
using namespace std ;

// time complexity is O(v*e)
// space complexity is O(v)
// below code is right implimentation of the ballman ford
// minimumn distance from src to all the other nodes 
vector<int> Bellman_Ford(vector<vector<int>>&edges , int src , int v){
    int m=edges.size();
    vector<int> dist(v,INT_MAX);
    dist[src]=0;
    for(int i=1;i<=v-1;i++){
        for(int j=0;j<m;j++){
            if(dist[edges[j][0]]==INT_MAX){
                continue;
            }
            if(dist[edges[j][0]]+edges[j][2] < dist[edges[j][1]]){
                dist[edges[j][1]] = dist[edges[j][0]]+edges[j][2];
            }
        }
    }
    for(int j=0;j<m;j++){
         if(dist[edges[j][0]]==INT_MAX) continue;
        if(dist[edges[j][0]]+edges[j][2] < dist[edges[j][1]]){
            return{-1};
        }
    }
    for(int i=0;i<v;i++){
        if(dist[i]==INT_MAX){
            dist[i]=1e8;
        }
    }
    
    return dist;
}

int main(){

}