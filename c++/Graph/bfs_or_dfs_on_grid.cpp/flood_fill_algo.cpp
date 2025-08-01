#include<bits/stdc++.h>
using namespace std;

// using bfs 
// time complexity is O(n*m)
// space complexity is o(n*m)

vector<vector<int>> bfs_on_grid(vector<vector<int>>&arr,int sr,int sc,int color){
    int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>> visited(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=color;
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        while(!q.empty()){
            auto f=q.front();
            int r=f.first;
            int c=f.second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+dx[i];
                int col=c+dy[i];
                if(row>=0 && col>=0 && row<m && col<n){
                    if(visited[row][col]!=color && arr[r][c]==arr[row][col]){
                        q.push({row,col});
                        visited[row][col]=color;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==-1){
                    visited[i][j]=arr[i][j];
                }
            }
        }
        return visited;
}

// space eoptimiozation 
// time compelxity is o(n*m)
// space complexity is o(1)

vector<vector<int>> space_opti(){
    int m=arr.size();
        int n=arr[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        while(!q.empty()){
            auto f=q.front();
            int r=f.first;
            int c=f.second;
            int temp=arr[r][c];
            arr[r][c]=color;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r+dx[i];
                int col=c+dy[i];
                if(row>=0 && col>=0 && row<m && col<n){
                    if(arr[row][col]==temp && arr[row][col]!=color){
                        q.push({row,col});
                    }
                }
            }
        }
        return arr;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<nlj++){
            cin>>arr[i][j];
        }
    }
    cout<<"using bfs "<<endl;
    
}