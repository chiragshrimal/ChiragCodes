#include<bits/stdc++.h>
using namespace std;

// using bfs apporach
// time complexity is O(n*m)
// space complexity is O(n*m)+o(n*m)
vector<vector<int>> solve(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }
    vector<int> row(4,0);
    row[0]=-1;
    row[2]=1;
    vector<int> col(4,0);
    col[1]=1;
    col[3]=-1;
    while(!q.empty()){
        auto it =q.front();
        int x=it.first.first;
        int y=it.first.second;
        int val=it.second;
        q.pop();
        ans[x][y]=val;
        for(int i=0;i<4;i++){
            int r=x+row[i];
            int c=y+col[i];
            if(r>=0 && c>=0 && r<n && c<m){
                if(visited[r][c]==0){
                    visited[r][c]=1;;
                    q.push({{r,c},val+1});
                }
            }
        }
    }
    return ans;
}


int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> ans=solve(mat);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}