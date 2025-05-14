#include<bits/stdc++.h>
using namespace std;

// find fibo number

// brute force apporach 
// time complexity is O(2^n)
// space compelxity is O(n)-->stack size 

int fibo_brute(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo_brute(n-1)+fibo_brute(n-2);
}

// using memorization or top-down apporach 
// time complexity is O(2*n)
// space complexity is O(2*n) --> stack + dp

int fibo_topDown(int n, vector<int>&dp ){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fibo_topDown(n-1,dp)+fibo_topDown(n-2,dp);
}


// using tabulation or bottom-up apporach 
// time compelxity is O(n)
// space complexity is O(n)

int fibo_bottomUp(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


// optimal apporach 
// space optimization 
// time compplexity is O(n)
// space complexity is O(1)

int fibo_optimal(int n){
    int a=0;
    int b=1;
    int c=-1;
    for(int i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo_topDown(n,dp)<<endl;
}
