#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time compelxity is O(3^n*3^n)
// space complexity is O(n*m)

// this problem is the type of both end is variable 
// so you can start any where .
int brute_apporach(vector<vector<int>>&arr,int row,int col){
    if(col<0 || col>=arr[0].size()){
        return INT_MAX;
    }
    if(row==0){
        return arr[0][col];
    }
    int pick=arr[row][col]+min(brute_apporach(arr,row-1,col),min(brute_apporach(arr,row-1,col-1),brute_apporach(arr,row-1,col+1)));
    return pick;
}

// brute optimal apporach 
// time complexiity is O(n*m)
// space complexity is O(n*m)

int brute_optimal(vector<vector<int>>&arr,vector<vector<int>>&dp, int row,int col){
     if(col<0 || col>=arr[0].size()){
        return INT_MAX;
    }
    if(row==0){
        return arr[0][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int pick=arr[row][col]+min(brute_apporach(arr,row-1,col),min(brute_apporach(arr,row-1,col-1),brute_apporach(arr,row-1,col+1)));
    return dp[row][col] = pick;
}

// bottom up apporach 
// using different defination of the dp 
// time compelxity is O(n*m)
// space complexity is o(n*m)

int bottom_up_apporach(vector<vector<int>>&arr){
   int n=arr.size();
   int m=arr[0].size();
   vector<vector<int>> dp(n,vector<int>(m,0));
   for(int i=0;i<m;i++){
    dp[0][i]=arr[0][i];
    // cout<<dp[0][i]<<endl;
   }
   for(int i=1;i<n;i++){
    for(int j=0;j<m;j++){
        int up=INT_MAX;
        int left=INT_MAX;
        int right=INT_MAX;
        // up always define 
        up=min(up,dp[i-1][j]);

        // for left
        if(j-1>=0){
            left=min(left,dp[i-1][j-1]);
        }

        // for right
        if(j<=m-2){
            right=min(right,dp[i-1][j+1]);
        }
        dp[i][j]= arr[i][j] + min(up,min(left,right));
    }
   }

   int mini=INT_MAX;
   for(int i=0;i<m;i++){
    mini=min(mini,dp[n-1][i]);
   }
   return mini;
}

// space optimization 
// time compleity is O(n*m)
// space complexity is O(m)

int space_optimization(vector<vector<int>>& arr){
    int n=arr.size();
   int m=arr[0].size();
   vector<int>pre(m,0);
   for(int i=0;i<m;i++){
    pre[i]=arr[0][i];
   }
   for(int i=1;i<n;i++){
    vector<int>temp(m,0);
    for(int j=0;j<m;j++){
        int up=INT_MAX;
        int left=INT_MAX;
        int right=INT_MAX;
        // up always define 
        up=min(up,pre[j]);

        // for left
        if(j-1>=0){
            left=min(left,pre[j-1]);
        }

        // for right
        if(j<=m-2){
            right=min(right,pre[j+1]);
        }
        temp[j]= arr[i][j] + min(up,min(left,right));
    }
    pre=temp;
   }

   int mini=INT_MAX;
   for(int i=0;i<m;i++){
    mini=min(mini,pre[i]);
   }
   return mini;
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"using brute apporach "<<endl;
    int brute=INT_MAX;
    for(int i=0;i<m;i++){
    
        brute=min(brute,brute_apporach(arr,n-1,i));
    }
    cout<<brute<<endl;

    cout<<"using brute optimal apporach "<<endl;
    
    int optimal=INT_MAX;
    for(int i=0;i<m;i++){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    optimal=min(optimal,brute_optimal(arr,dp,n-1,i));
    }
    cout<<optimal<<endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;

    cout<<"using space optimization"<<endl;
    int space=space_optimization(arr);
    cout<<space<<endl;

}