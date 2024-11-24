#include<bits/stdc++.h>
using namespace std;
// brute force apporach 
// time complexity is O(n^2)
// space complexity is O(n^2)
vector<vector<int>>  rotation_matrix_brute(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    vector<vector<int>> ans(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][m-1-i]=v[i][j];
        }
    }
    return ans;

}
// optimal apporach 
// time complexity is O(n^2)
// space complexity is O(1)
// apporach is 
// 1. transpose the matrix
// and reverse row wise
void rotation_matrix_optimal(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    // transpose of the matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    // reverse row wise
    for(int i=0;i<n;i++){
        reverse(v[i].begin(),v[i].end());
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> v[i][j];
        }
    }
    // vector<vector<int>> ans;
    // ans=rotation_matrix_brute(v);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    rotation_matrix_optimal(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}