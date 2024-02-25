#include<bits/stdc++.h>
using namespace std;

void f(int arr[],int l,int n,vector<vector<int>> v,vector<int>ds){
    v.push_back(ds);
    
    for(int i=l;i<n;i++){
        if(arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        f(arr,l+1,n,v,ds);
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
}
}