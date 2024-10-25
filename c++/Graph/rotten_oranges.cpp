#include<bits/stdc++.h>
using namespace std;

// time complexity is O(n*m)
// space complexity is O(n*m)
int solve(vector<vector<int>>& grid){k
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push(pair(pair(i,j),0));
                visited[i][j]=1;
            }
        }
    }
    int time=0;
    vector<int> row(4,0);
    vector<int> col(4,0);
    row[0]=-1;
    row[2]=1;
    col[1]=1;
    col[3]=-1;
    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int t=q.front().secopnd;
        q.pop();
        time=max(time,t);
        for(int i=0;i<4;i++){
            int r1=x+row[i];
            int r2=y+col[i];
            if(r1<n && r2<m && r1>=0 && r2>=0 && visited[r1][r2]==0){
                q.push(pair(pair(r1,r2),t+1));
                visited[r1][r2]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return time;
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid)<<endl;

}