#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto value:v){
        cout<<value;
    }
    cout<<endl;
}
int sum(vector<int> v){
    int sum=0;
    for(auto value: v){
        sum+=value;
    }
    return sum;
}


// we can take any number many time 

void f(int arr[],int l,int n,int target,vector<int> v){
    if(l==n){
        if(target==0){
            print(v);
        }
        return ;
    }
    if(arr[l]<=target){
        v.push_back(arr[l]);
        f(arr,l,n,target-arr[l],v);
        v.pop_back();
    }
    f(arr,l+1,n,target,v);
}


int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target=3;
    vector<int> v;
    f(arr,0,n,target,v);
}