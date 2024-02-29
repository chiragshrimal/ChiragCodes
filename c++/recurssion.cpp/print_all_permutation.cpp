#include<bits/stdc++.h>
using namespace std;


// solving without frequency array 

void g(int ind,int arr[],int n,vector<vector<int>> &v){
    if(ind==n){
        vector<int>s;
        for(int i=0;i<n;i++){
            s.push_back(arr[i]);
        }
        v.push_back(s);
        return;
    }

    for(int i=ind;i<n;i++){
        swap(arr[i],arr[ind]);
        g(ind+1,arr,n,v);
        swap(arr[i],arr[ind]);
    }
}



void f(int *arr,int l,int n,vector<vector<int>>&s,vector<int> &v,int *frr){
    if(v.size()==n){
        s.push_back(v);
        return;
    }
    for(int i=l;i<n;i++){
        if(frr[i]==0){
        v.push_back(arr[i]);
        frr[i]=1;
        f(arr,l,n,s,v,frr);
        }else{
            continue;
        }
        v.pop_back();
        frr[i]=0;
    }
}

int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int frr[n]={0};
    vector<vector<int>> s;
    vector<int> v;
    f(arr,0,n,s,v,frr);
    for(auto set : s){
        for(auto value : set){
            cout<<value;
        }
        cout<<endl;
    }
     vector<vector<int>> k;
    g(0,arr,n,k);
    for(auto set : k){
        for(auto value : set){
            cout<<value;
        }
        cout<<endl;
    }
}