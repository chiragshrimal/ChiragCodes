#include<bits/stdc++.h>
using namespace std;

vector<int>s;
int f(vector<vector<int>> &v,int n,int fre[],int cost){
    if(s.size()==n){
        return cost;
    }
    for(int i=0;i<n;i++){
        if(fre[i]==0){
            f()
        }
    }

}
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    vector<vector<int>> v;
    cout<<"enter values"<<endl;
    for(int i=1;i<n;i++){
        vector<int> ds;
        for(int j=1;j<n;j++){
            int x;
            cin>>x;
            ds.push_back(x);
        }
        v.push_back(ds);
    }

}