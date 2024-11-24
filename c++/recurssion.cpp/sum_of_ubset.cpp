#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void subset_sum(int arr[],int l,int h,int sum){
    if(l>h){
        v.push_back(sum);
        return;
    }
    subset_sum(arr,l+1,h,sum+arr[l]);
    subset_sum(arr,l+1,h,sum);

}

int main(){
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subset_sum(arr,0,n-1,0);
    for(auto value : v){
        cout<<value<<endl;
    }

}