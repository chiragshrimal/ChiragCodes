#include<bits/stdc++.h>
using namespace std;

// n==1e5

// brute force apporach 
// time complexity is O(2^n)
// space complexity is O(n);
int brute(int index1,int index2,vector<int>&arr,vector<vector<int>>&dp){

}
// // top-Down appoe=rach 
// // time complexity is O(n*n)
// // space complexity is O(n*n)+O(n);
int top_down(int index1,int index2,vector<int>& arr,vector<vector<int>> & dp){
    if(index1<0){
        return 0;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    int l1=INT_MIN;
    if(index2==arr.size() || arr[index1]<arr[index2]){
        l1=1+top_down(index1-1,index1,arr,dp);
    }
    int l2=top_down(index1-1,index2,arr,dp);
    return dp[index1][index2]=max(l1,l2);
}

// bottom up apporach 
// time complexity is O(n*n)
// space complexity is O(n*n)
int bottom_up(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int l1=INT_MIN;
            if(j==0 || arr[i-1]<arr[j-1]){
                l1=1+dp[i-1][j];
            }
            int l2=dp[i-1][j];
            dp[i][j+1]=max(l1,l2);
            // cout<<dp[i][j]<<endl;
        }
    }
    return dp[n][n];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<bottom_up(arr);
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // cout<<top_down(n-1,n,arr,dp);
    
}