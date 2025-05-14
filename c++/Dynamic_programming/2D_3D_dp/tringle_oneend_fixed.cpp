#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time compelxity is O(2^n)
// space complexity is O(n*m)

// this problem is the type of one fixed end and another end is variable 
// this type of problem make bigger problem is that fixed end and smaller is variable end 
int brute_apporach(vector<vector<int>>&arr,int row,int col){
    if(row==arr.size()-1){
        return arr[row][col];
    }
    int pick= arr[row][col]+ min(brute_apporach(arr,row+1,col),brute_apporach(arr,row+1,col+1));
    return pick;
}

// brute optimal apporach 
// time complexiity is O(n*m)
// space complexity is O(n*m)

int brute_optimal(vector<vector<int>>&arr,vector<vector<int>>&dp, int row,int col){
    if(row==arr.size()-1){
        return arr[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int pick= arr[row][col]+ min(brute_optimal(arr,dp,row+1,col),brute_optimal(arr,dp,row+1,col+1));
    return dp[row][col] = pick;
}

// bottom up apporach 
// using different defination of the dp 
// time compelxity is O(n*m)
// space complexity is o(n*m)

int bottom_up_apporach(vector<vector<int>>&arr){
    int m=arr.size();
    int n=arr[m-1].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0]=arr[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<i+1;j++){
            if(i==0 && j==0)
            continue;
            int dia=INT_MAX;
            if(i>0 && j>0){
                dia=arr[i][j]+dp[i-1][j-1];
            }
            int up=INT_MAX;
            if((i)!=j){
                up=arr[i][j]+dp[i-1][j];
            }
            dp[i][j]=min(up,dia);
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,dp[m-1][i]);
    }
    return mini;
}

// space optimization 
// time compleity is O(n*m)
// space complexity is O(m)

int space_optimization(vector<vector<int>>& arr){
    int m=arr[0].size();
    int n=arr.size();
    vector<int> pre(m,0);
    for(int i=0;i<m;i++){
        pre[i]=arr[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
        vector<int> temp(m,0);
        for(int j=0;j<=m-(n-i)+1;j++){
            temp[j]=arr[i][j]+min(pre[j],pre[j+1]);
        }
        pre=temp;
    }
    return pre[0];
    
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"using brute apporach "<<endl;
    int brute=brute_apporach(arr,0,0);
    cout<<brute<<endl;

    cout<<"using brute optimal apporach "<<endl;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int optimal_brute =brute_optimal(arr,dp,0,0);
    cout<<optimal_brute<<endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;

    cout<<"using space optimization"<<endl;
    int space=space_optimization(arr);
    cout<<space<<endl;

}