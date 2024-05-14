#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity is O(n^3)
// space complexity is O(n^2);
void set_zeroes_brute(vector<vector<int>> &v, int n, int m)
{
    vector<pair<int, int>> stored;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                stored.push_back(pair(i, j));
            }
        }
    }
    for (auto it : stored)
    {
        for (int j = 0; j < m; j++)
        {
            v[it.first][j] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            v[j][it.second] = 0;
        }
    }
    return;
}
//right brute force apporach 
// time complexity is o(n^3)
// space complexity is O(1)
void  row(vector<vector<int>> &v ,int i, int m){
    for(int j=0;j<m;j++){
        if(v[i][j]!=0)
        v[i][j]=-1;
    }
}
void colunm(vector<vector<int>> &v , int j, int n){
    for(int k=0;k<n;k++){
        if(v[k][j]!=0)
        v[k][j]=-1;
    }
}
void set_zeroes_brute2(vector<vector<int>> &v ,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                row(v,i,m);
                colunm(v,j,n);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==-1){
                v[i][j]=0;
            }
        }
    }
    return ;
}
//  better apporach 
// time complexity is  O(n^2)
// space complexity is O(m+n)
void set_zeroes_better(vector<vector<int>> &v,int n,int m){
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(col[i]==1){
            for(int j=0;j<n;j++){
                v[j][i]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(row[i]==1){
            for(int j=0;j<m;j++){
                v[i][j]=0;
            }
        }
    }

}
// optimal apporach  // goood prectice  for coding 
// time complexity is O(n^2)
// space complexity is o(1)
void set_zeroes_optimal(vector<vector<int>> &v, int n, int m){
    int col=1;// extra for column 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                if(j==0 && v[i][j]==0){
                    col=0;
                }else{
                    v[0][j]=0;
                    v[i][0]=0;
                }
                
            }
        }
    }
    // remaining n-1* m-1 matrix ko solve kiya 
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[0][j]==0 || v[i][0]==0){
                v[i][j]=0;
            }
        }
    }
    // col wali row ko solve kiya 
    if(v[0][0]==0){
        for(int j=0;j<m;j++){
            v[0][j]=0;
        }
    }
    // row wali col ko solve kiya 
    if(col==0){
        for(int i=0;i<n;i++){
            v[i][0]=0;
        }
    }
    return ;
}
int main()
{
    int n, m;
    cin >> n >> m;
    // int arr[n][m];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    vector<vector<int>> v(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>v[i][j];
        }
    }
    // set_zeroes_brute2(v, n, m);
    // set_zeroes_better(v,n,m);
    set_zeroes_optimal(v,n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j]<<"   ";
        }
        cout<<endl;
    }


    return 0;
}