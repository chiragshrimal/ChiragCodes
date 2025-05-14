#include<bits/stdc++.h>
using namespace std;

// brute apporach 
// time complexity is O(2^n)
// space complexity is O(n)

int brute_apporach(int n,vector<int>&arr){

    if(n==0){
        return arr[0];
    }
    if(n==1){
        return max(arr[0],arr[1]);
    }
    // pick
    int pick=arr[n]+brute_apporach(n-2,arr);
    int dontpick=brute_apporach(n-1,arr);
    return max(pick,dontpick);
}

// optimal apporach 
// apply top down with dp 
// time complexity is o(2*n)
// space complexity is o(n)

int top_down_optimal_apporach(int n,vector<int>&arr,vector<int>&dp){
   if(n==0){
        return arr[0];
    }
    if(n==1){
        return max(arr[0],arr[1]);
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    // pick
    int pick=arr[n]+top_down_optimal_apporach(n-2,arr,dp);
    // dontpick
    int dontpick=top_down_optimal_apporach(n-1,arr,dp);
    return dp[n]= max(pick,dontpick);
}

// apply bottom apporach 
// time complexity is o(n)
// space complexity is O(n)

int bottom_apporach(int n,vector<int>&arr){
    vector<int> dp(n+1,0);
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<=n;i++){
        int pick=arr[i]+dp[i-2];
        int dontpick=dp[i-1];
        dp[i]=max(pick,dontpick);
    }
    return dp[n];
}

// do space optimizadtion 
// time  complexity is O(n)
// space copmplexity is o(1)
// here n means index se hai all the questions 
int space_optimization(int n,vector<int>&arr){
    int a=arr[0];
    int b=max(arr[0],arr[1]);
    int c=-1;
    if(n==0){
        return a;
    }
    if(n==1){
        return b;
    }
    for(int i=2;i<=n;i++){
        c=max(arr[i]+a,b);
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