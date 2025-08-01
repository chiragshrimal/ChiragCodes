#include<bits/stdc++.h>
using namespace std ;

// using dfs 
// time complexity is o(v+E)
// space complexity is o(V)

void cycle_detected(int start,unordered_map<int,vector<int>>&map,vector<int>&visited,vector<int>&path,int &time, int &val){
    time++;
    visited[start]=1;
    path[start]=time;
    int size=map[start].size();
    for(int i=0;i<size;i++){
        if(visited[map[start][i]]==0){
            cycle_detected(map[start][i],map,visited,path,time,val);
        }else{
            if(path[map[start][i]]!=0){
                val=max(val,time-path[map[start][i]].second+1);
            }
        }
    }
    path[start]=0;
    time--;
}


int main(){
    int n;
    cin>>n;
    // total number of entry in the map;
    int m;
    cin>>m;
    vector<int>visited(n,0);
    unordered_map<int,vector<int>>map;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        map[x].push_back(y);
    }
    vector<pair<int,int>>path(n,pair<int,int>{0,0});
    int val=-1;
    for(int i=0;i<n;i++){
        if(visited[i]==0 ){
         cycle_detected(i,map,visited,path,0,val);
        }
    }
    cout<<val<<endl;
    return val;
}