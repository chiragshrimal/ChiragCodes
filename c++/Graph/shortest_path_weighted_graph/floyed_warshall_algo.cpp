#include<bits/stdc++.h>
using namespace std ; 

// floyed_warshall algorithm
// i am written for directed graph 
// it sam efor undirected graph also 
// time complexity is O()
// space complexity is o()

vector<vector<int>> fun(vector<vector<int>>&matrix,int n){
    int m=matrix.size();
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<m;i++){
        dist[matrix[i][0]][matrix[i][1]]=matrix[i][2];
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    // iterate over all the intermidiate 
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    // nagative weight cycle detected
    for(int i=0;i<n;i++){
        if(dist[i][i]<0){
            dist[i][i]=INT_MIN;
        }
    }
    return dist;
}

int main(){

}