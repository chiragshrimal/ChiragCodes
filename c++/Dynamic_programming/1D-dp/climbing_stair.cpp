#include<bits/stdc++.h>
using namespace std;

// brute apporach 
// time complexity is O(2^n)
// space complexity is O(n)

int brute_apporach(int n){

    if(n==1|| n==2){
        return n;
    }
    int one=brute_apporach(n-1);
    int two=brute_apporach(n-2);
    return one+two;
}

// optimal apporach 
// apply top down with dp 
// time complexity is o(2*n)
// space complexity is o(n)

int top_down_optimal_apporach(int n,vector<int>&dp){
    if(n==1 || n==2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int one=top_down_optimal_apporach(n-1,dp);
    int two=top_down_optimal_apporach(n-2,dp);
    return dp[n]=one+two;
}

// apply bottom apporach 
// time complexity is o(n)
// space complexity is O(n)

int bottom_apporach(int n){
    vector<int> dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    if(n==1 || n==2){
        return n;
    }
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}

// do space optimizadtion 
// time  complexity is O(n)
// space copmplexity is o(1)
int space_optimization(int n){
    int a=1;
    int b=2;
    int c=-1;
    if(n==1 || n==2){
        return n;
    }
    for(int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    cout<<"using brute apporach "<<endl;
    int brute=brute_apporach(n);
    cout<<brute<<endl;

    vector<int> dp(n+1,-1);
    cout<<"using dp "<<endl;
    int optimal=top_down_optimal_apporach(n,dp);
    cout<<optimal<<endl;

    cout<<"using bottom apporach"<<endl;
    int bottom=bottom_apporach(n);
    cout<<bottom<<endl;

    cout<<"using space optimization"<<endl;
    int space=space_optimization(n);
    cout<<space<<endl;
}