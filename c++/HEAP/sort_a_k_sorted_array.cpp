#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complexity is O(nlog(n));
// space complexity is O(log(k));

void optimal_apporach(vector<int>&arr,int k){
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>> h;
    int z=0;
    for(int i=0;i<n;i++){
        h.push(arr[i]);
        if(z-i==k){
            arr[z]=h.top();
            h.pop();
            z++;
        }
    }
    while(!h.empty()){
        arr[z]=h.top();
        h.pop();
        z++;
    }
    return ;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    optimal_apporach(arr,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}