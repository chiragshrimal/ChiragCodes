#include<bits/stdc++.h>
using namespace std;

// optimal apporach 
// time complexity is O(n*m)
// space complexity is O(n*m)

int Counting_Squre(vector<vector<int>>&arr){
int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int count=0; 
        for(int i=0;i<m;i++){
            dp[0][i]=arr[0][i];
            if(dp[0][i]==1){
                count++;
            }
        }
        for(int i=1;i<n;i++){
            dp[i][0]=arr[i][0];
            if(dp[i][0]==1){
                count++;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]!=0){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    count+=dp[i][j];
                }
            }
        }
        return count;
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
    int ans=solve(arr);
    cout<<ans<<end;
}