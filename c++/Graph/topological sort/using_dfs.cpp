#include<bits/stdc++.h>
using namespace std;

// using dfs 
// time complexity is O(v+E)
// space complexity is o(v+v+v)

void dfs(int start, unordered_map<int,vector<int>>&map, vector<int>&visited,vector<int>&ans,vector<int>&indegree){
    ans.push_bacK(start);
    visited[i]=1;
    for(auto v : map){
        indegree[v]--;
        if(indegree[v]==0){
            dfs(v,map,visited,ans,indegree);
        }
    }
    return ;
}

// optimize space compleity
// time complexity is O(v+E)
// space compleixty is o(v+v)

void optimize_dfs(int start, unordered_map<int,vector<int>>&map,vector<int>&visited,vector<int>&ans){
    visited[start]=1;
    for(auto  v : map[start]){
        if(visited[v]==0){
            dfs(v,map,visited,ans);
        }
    }
    ans.push_back(start);
    return ;
}


int main(){
    int n;
    cin>>n;
    // size of map
    int m;
    cin>>m;
    unordered_map<int,vector<int>> map;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int y;
        cin>>y;
        map[x].push_back(y);
    }
    vector<int>indegree(n,0);
    for(auto it : map){
        for(auto v : it.second){
            indegree[v]++;
        }
    }
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(indegree[i]==0 && visited[i]==0){
            dfs(i,map,visited,ans,indegree);
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

    // using optimize space complexity 
    vector<int>ans2;
    vector<int>visited2(n,0);
    for(int i=0;i<n;i++){
        if(visited2[i]==0){
            dfs(i,map,visited2,ans2);
        }
    }
    revrese(ans2.begin(),ans.end());
    cout<<"using optimize space "<<endl;
    for(auto it : ans2){
        cout<<it<<" ";
    }
    cout<<endl;
    return ;
}