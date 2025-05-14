#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complexity is O(nlog(k))
// space complexity is O(log(k));


int optimal_apporach(vector<int>&arr,int k){
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>> h;
    for(int i=n-1;i>=0;i--){
        h.push(arr[i]);
        if(h.size()>k){
            h.pop();
        }
    }
    return h.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int optimal=optimal_apporach(arr,k);
    cout<<optimal<<endl;
}