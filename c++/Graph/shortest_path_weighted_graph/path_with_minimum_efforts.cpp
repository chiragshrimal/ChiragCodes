#include<bits/stdc++.h>
using namespace std;

// time complexity is o()
// space complexity is O()

int path_with_minimum_efforts(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<vector<int>>E(n,vector<int>(m,INT_MAX));
    E[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> minHeap;
    minHeap.push({0,{0,0}});
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    while(!minHeap.empty()){
        auto it = minHeap.top();
        int node_effort=it.first;
        int r=it.second.first;
        int c=it.second.second;
        minHeap.pop();
        for(int i=0;i<4;i++){
            int row=r+dx[i];
            int col=c+dy[i];
            if(row>=0 && col>=0 && row<n && col<m){
                int dif=max(node_effort,abs(arr[row][col]-arr[r][c]));
                if(E[row][col]<dif){
                    E[row][col]=dif;
                    minHeap.push({dif,{row,col}});
                }
            }
        }
    }
    return E[row-1][col-1];
}

int main(){

}