#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(2^n)
// space complexity is O(n)

int brute_apporach(int index,vector<int>& arr,int target){
    if(index==0){
        if(target==0 && target==arr[0]){
            return 2;
        }
        if(target==arr[0] || target==-arr[0]){
            return 1;
        }
        return 0;
    }

    int take_negative=brute_apporach(index-1,arr,target-arr[index]);
    int take_positive=brute_apporach(index-1,arr,target+arr[index]);

    return take_positive+take_negative;
}
// we can solve this problem usig two subset differences


int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<brute_apporach(n-1,arr,target);
}