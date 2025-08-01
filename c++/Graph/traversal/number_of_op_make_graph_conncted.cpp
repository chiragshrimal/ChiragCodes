#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>&graph,vector<int>&visited){
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto v: graph[f]){
            if(visited[v]==0){
                q.push(v);
                visited[v]=1;
            }
        }
    }
    return ;
}

int minimum_edge(int n ,vector<vector<int>>&arr){
    int m=arr.size();
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++){
        graph[arr[i][0]].push_back(arr[i][1]);
        graph[arr[i][1]].push_back(arr[i]0);
    }
    vector<int>visited(n,0);
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            bfs(i,graph,visited);
            c++;
        }
    }
    int edges_req=m-(n-c);
    if(edges_req>=c-1){
        cout<<c-1<<endl;
        return ;
    }
    cout<<-1<<endl;
    return ;
}

int main(){

}