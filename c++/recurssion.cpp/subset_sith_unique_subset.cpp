#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
void f(int arr[],int l,int n,vector<int>&ds){
    v.push_back(ds);
    for(int i=l;i<n;i++){
        if(i!=l && arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        f(arr,i+1,n,ds);
        ds.pop_back();
    }
}
int main(){
int n;
cout<<"enter a number"<<endl;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}//sort krke bhejna pdega 
//function m 
vector<int> ds;
f(arr,0,n,ds);
for(auto set :v){
    for(auto value :set){
        cout<<value;
    }
    cout<<endl;
}
}