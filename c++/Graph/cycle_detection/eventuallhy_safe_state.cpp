#include<bits/stdc++.h>
using namespace std ;

// using dfs 
// time complexity is o(v+E)
// space complexity is o(V)

bool cycle_detected(int start , unordered_map<int,vector<int>>&map,vector<int>&visited,vector<int>&path,unordered_set<int>&s){
    visited[start]=1;
    path[start]=1;
    int size=map[start].size();
    for(int i=0;i<size;i++){
        if(visited[map[start][i]]==0){
            bool ans=cycle_detected(map[start][i],map,visited,path);
            if(ans==true){
                s.insert(start);
            return true;
            }
        }else{
            if(path[map[start][i]]==1){
                s.insert(start);
                return true;
            }
        }
    }
    path[start]=0;
    return false;
}


int main(){
    int n;
    cin>>n;
    // total number of entry in the map;
    int m;
    cin>>m;
    unordered_map<int,vector<int>>map;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        map[x].push_back(y);
    }
    vector<int>path(n,0);
    int count=0;
    // all unsafe node are stored in the s;
    unordreed_set<int> s;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(s.find(i)==s.end() ){
            
        }
    }
    // total node- unsafe node
    for(int i=0;i<n;i++){
        if(s.find(i)==s.end()){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}