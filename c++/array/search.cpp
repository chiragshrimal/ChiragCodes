#include<bits/stdc++.h>
using namespace std;

bool linear_search(int n,int arr[],int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return true;
        }
    }
    return  false;
}
int main(){
    int n;
    cout<<"enter a number\n";
    cin>>n;
    int arr[n];
    cout<<"enter elsement of array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    bool check=linear_search(n,arr,k);
    if(check==1){
        cout<<"find";
    }else{
        cout<<"not find";
    }
    return 0;
}