#include<bits/stdc++.h>
using namespace std;

// using DFS
// time complexity is O(n^2)
// space complexity is o(v+v+v+v)

void dfs(int start,int parent,int d, vector<int>&dis,unordered_map<int,vector<int>>&map,int &ans){

        dis[start]=d;
        for(auto v: map[start]){
            if(v==parent){
                continue;
            }
            if(dis[start]>dis[v]){
                ans=min(ans,dis[start]-dis[v]+1);
            }else{
                if(dis[start]+1<dis[v]){
                    dfs(v,start,d+1,dis,map,ans);
                }
            }
        }
        return ;

    }
    int findShortestCycle(int n, vector<vector<int>>& arr) {
        int m=arr.size();
        unordered_map<int,vector<int>> map;
        for(int i=0;i<m;i++){
            map[arr[i][0]].push_back(arr[i][1]);
            map[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int>dis(n,INT_MAX);
        int ans=n+1;
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX){
                dfs(i,-1,0,dis,map,ans);
            }
        }
        if(ans==n+1){
            return -1;
        }
        return ans;

    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        cin>>v[i][1];
    }
    int ans=dfs(n,arr);
    cout<<ans<<endl;
}