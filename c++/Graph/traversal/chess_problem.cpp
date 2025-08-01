#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// using bfs 
// time compelxity is O(v+E)
// space compelexity is O(V)

int BFS(int i,int j, int d1,int d2,int n){
    int count=0;
    // first convert i,j into d1 and d2
    i=n-i;
    j=n-j-1;
    vector<vector<int>>visited(n,vector<int>(n,0));
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=1;
    vector<int>row(8,0);
    vector<int>col(8,0);
    // for row 
    int i=0,k=2,l=1,j=7;
    while(i<j){
        row[j]=row[j-1]=k;
        row[i]=row[i+1]=-k;
        col[i]=-l;
        col[i+1]=l;
        col[j]=1;
        col[j-1]=-1;
        k--;
        i+=2;
        j-=2;
        l++;
    }
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            if(r==d1 && c==d2){
                return count;
            }
            for(int i=0;i<8;i++){
                int new_row=r+row[i];
                int new_col=c+col[i];
                if(new_col>=0 && new_row<n && new_col>=0 && new_col<n){
                    q.push({new_row,new_col});
                    visited[new_row][new_col]=1;
                }
            }
        }
        count++;
    }
    return count;

}

int main(){
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    int d1,d2;
    cin>>d1>>d2;
    int ans=BFS(x,y,d1,d2,n);
    cout<<ans<<endl;
}