#include<bits/stdc++.h>
using namespace std;

// very important concept hai 
// time compelxity is O(n*m)
// space compelxity is O(n*m)

 vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &arr) {
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        vector<int>dx={1,-1,0,0};
        vector<int> dy={0,0,-1,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='W'){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int level=0;
            for(int i=0;i<size;i++){
            auto f=q.front();
            int r=f.first;
            int c=f.second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+dx[i];
                int col=c+dy[i];
                if(row>=0 && col>=0 && row<n && col<m){
                    if(visited[row][col]==0 && (arr[row][col]=='H' || arr[row][col]=='.')){
                        level=1;
                        dis[row][col]=ans+1;
                        q.push({row,col});
                        visited[row][col]=1;
                    }
                }
            }
            
            }
            ans+=level;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='.' || arr[i][j]=='W' || arr[i][j]=='N'){
                    dis[i][j]=0;
                }else{
                    if(dis[i][j]==0){
                        dis[i][j]=-1;
                    }else{
                        dis[i][j]=2*dis[i][j];
                    }
                }
            }
        }
        return dis;
    }

int main(){

}