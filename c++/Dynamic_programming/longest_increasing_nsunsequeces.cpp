#include<bits/stdc++.h>
using namespace std;

// n==1e5

// brute force apporach 
// time complexity is O(2^n)
// space complexity is O(n);
int brute(int index1,index2,vector<int>& arr){
    if(index1<0){
        return 0;
    }
    int l1=INT_MIN;
    if(index2==arr.size() || arr[index1]<arr[index2]){
        l1=1+brute(index1-1,index1,arr);
    }
    int l2=brute(index1-1,index2,arr);
    return max(l1,l2);
}

// top-Down appoe=rach 
// time complexity is O(n*n)
// space complexity is O(n*n)+O(n);
int top_down(int index1,int index2,vector<int>& arr,vector<vector<itn>> & dp){
    if(index1<0){
        return 0;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    int l1=INT_MIN;
    if(index2==arr.size() || arr[index1]<arr[index2]){
        l1=1+brute(index1-1,index1,arr);
    }
    int l2=brute(index1-1,index2,arr);
    return dp[index1][index2]=max(l1,l2);
}

// bottom up apporach 
// time complexity is O(n*n)
// space complexity is O(n*n)
int bottom_up(vector<int>&arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}