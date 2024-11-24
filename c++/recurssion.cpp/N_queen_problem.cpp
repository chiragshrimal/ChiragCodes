#include<bits/stdc++.h>
using namespace std;

bool is_safe(int row,int col,vector<vector<int>> &v,int n){
    // check up  condition 
    int r1=row-1; 
    int c1=col;
    while(r1>=0){
        if(v[r1][c1]==1){
            return false;
        }
        r1--;
    }
    int r2=row-1;
    int c2=col+1;
    // check right diognal
    while(c2<n && r2>=0 ){
        if(v[r2][c2]==1){
            return false;
        }
        r2--;
        c2--;
    }
    // check left digonal
    row--;
    col--;
    while(row>=0 && col>=0){
        if(v[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    return true;
}
vector<vector<vector<int>>> s;
void f(int row,vector<vector<int>> &v,int n){
    if(row==n){
        s.push_back(v);
        return ;
    }
    for(int i=0;i<n;i++){
        if(is_safe(row, i, v, n)){
            v[row][i]=1;
            f(row+1,v,n);
            v[row][i]=0;
        }
    }
}
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    f(0,v,n);
    for(auto vector : s){
        for(auto set :vector ){
            for(auto value : set){
                cout<<value<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}