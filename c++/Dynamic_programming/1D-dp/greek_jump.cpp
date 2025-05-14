#include<bits/stdc++.h>
using namespace std;

// brute apporach 
// time complexity is O(2^n)
// space complexity is O(n)

int brute_apporach(int n,vector<int>&arr){
    // index=0 par khade hone ki cost hai 
    if(n==0){
        return 0;
    }
    // index=1 par khade hone ki cost hai 
    if(n==1){
        return abs(arr[1]-arr[0]);
    }
    int one=abs(arr[n]-arr[n-1])+brute_apporach(n-1,arr);
    int two=abs(arr[n]-arr[n-2])+brute_apporach(n-2,arr);
    return min(one,two);
}

// optimal apporach 
// apply top down with dp 
// time complexity is o(2*n)
// space complexity is o(n)

int top_down_optimal_apporach(int n,vector<int>&arr,vector<int>&dp){
   // index=0 par khade hone ki cost hai 
    if(n==0){
        return 0;
    }
    // index=1 par khade hone ki cost hai 
    if(n==1){
        return abs(arr[1]-arr[0]);
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int one=abs(arr[n]-arr[n-1])+top_down_optimal_apporach(n-1,arr,dp);
    int two=abs(arr[n]-arr[n-2])+top_down_optimal_apporach(n-2,arr,dp);
    return dp[n]=min(one,two);
}

// apply bottom apporach 
// time complexity is o(n)
// space complexity is O(n)

int bottom_apporach(int n,vector<int>&arr){
    vector<int> dp(n,0);
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);
    for(int i=2;i<=n;i++){
        dp[i]=min(abs(arr[i]-arr[i-1])+dp[i-1],abs(arr[i]-arr[i-2])+dp[i-2]);
    }
    return dp[n];

}

// do space optimizadtion 
// time  complexity is O(n)
// space copmplexity is o(1)
int space_optimization(int n,vector<int>&arr){
    int a=0;
    int b=abs(arr[1]-arr[0]);
    int c=-1;
    for(int i=2;i<=n;i++){
        c=min(abs(arr[i]-arr[i-1])+b,abs(arr[i]-arr[i-2])+a);
        a=b;
        b=c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"using brute apporach "<<endl;
    int brute=brute_apporach(n-1,arr);
    cout<<brute<<endl;

    vector<int> dp(n,-1);
    cout<<"using dp "<<endl;
    int optimal=top_down_optimal_apporach(n-1,arr,dp);
    cout<<optimal<<endl;

    cout<<"using bottom apporach"<<endl;
    int bottom=bottom_apporach(n-1,arr);
    cout<<bottom<<endl;

    cout<<"using space optimization"<<endl;
    int space=space_optimization(n-1,arr);
    cout<<space<<endl;
}