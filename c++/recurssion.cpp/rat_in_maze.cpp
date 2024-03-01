#include<bits/stdc++.h>
using namespace std;


set<vector<char>>s;
bool up_safe(int row,int col,vector<vector<int>> v,vector<vector<int>>mark){
    if(row-1>=0 && v[row-1][col]==1 && mark[row-1][col]==0){
        return true;
    }
    return false;
}
bool down_safe(int row,int col,vector<vector<int>> v,vector<vector<int>>mark){
     if(row+1<v.size() && v[row+1][col]==1 && mark[row+1][col]==0){
        return true;
    }
    return false;
}
bool right_safe(int row,int col,vector<vector<int>> v,vector<vector<int>>mark){
     if(col+1 < v.size() && v[row][col+1]==1 && mark[row][col+1]==0){
        return true;
    }
    return false;
}

bool left_safe(int row,int col,vector<vector<int>> v,vector<vector<int>>mark){
     if(col-1>=0 && v[row][col-1]==1 && mark[row][col-1]==0){
        return true;
    }
    return false;
}

void f(int row,int col,vector<vector<int>> &v,vector<vector<int>> &mark,vector<char> c){
    if(row==v.size()-1 && col==v.size()-1){
        s.insert(c);
        return ;
    }
    if(up_safe(row,col,v,mark)){// for up
       mark[row-1][col]=1;
       c.push_back('U');
       f(row-1,col,v,mark,c);
        mark[row-1][col]=0;
       c.pop_back();
       
    }
    if(down_safe(row,col,v,mark)){
        mark[row+1][col]=1;
       c.push_back('D');
       f(row+1,col,v,mark,c);
        mark[row+1][col]=0;
       c.pop_back();
    }

    if(right_safe(row,col,v,mark)){
       mark[row][col+1]=1;
       c.push_back('R');
       f(row,col+1,v,mark,c);
          mark[row][col+1]=0;
       c.pop_back();
    }
    if(left_safe(row,col,v,mark)){
       mark[row][col-1]=1;
       c.push_back('L');
       f(row,col-1,v,mark,c);
       mark[row][col-1]=0;
       c.pop_back();
    }
}

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> mark(n,vector<int>(n));
    vector<char> c;
    f(0,0,v,mark,c);
    for(auto vector : s){
        for(auto value : vector){
            cout<<value;
        }
        cout<<endl;
    }

}