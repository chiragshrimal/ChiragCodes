#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(2^n)
// space complexity is O(amount+n)
int brute_force(int index,vector<int>& w,int amount){
    if(index==0){
        if(amount==0){
            return 1;
        }else{
            if(amount%w[0]==0){
                return amount/w[0];
            }
        }
    }
    int take=INT_MAX;
    if(amount>=w[index]){
        take=1+brute_force(index,w,amount-w[index]);
    }
    int not_take=brute_force(index-1,w,amount);

    return min(take,not_take);
}

// top-down apporach 
// time complexity is O(n*amount);
// space complexity is O(n*amount)+(n);

int top_down(int index,vector<int>& w,int amount,vector<vector<int>>& dp){
    if(index==0){
        if(amount==0){
            return 0;
        }else{
            if(amount%w[0]==0)[
                return amount/w[0];
            ]
        }
        return INT_MAX;
    }

    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    
    int take=INT_MAX;
    if(amount>=w[index]){
        take=1+top_down(index,w,amount-w[index],dp);
    }
    int not_take=top_down(index-1,w,amount,dp);
    
    return dp[index][amount]=min(take,not_take);
}

// bottom apporach 
// time complexity is O(n*amount)
// space complexity is O(n*amount)

int bottom_apporach(vector<int>& w,int amount,int n){
    vector<vector<int>> dp(n,vector<int>(amount+1,0));
    if(amount==0){
        return 0;
    }
    for(int i=1;i<=amount;i++){
        if(i%w[0]==0){
            dp[0][i]=i/w[0];
        }else{
            dp[0][i]=INT_MAX;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=amount;i++){
            int take=INT_MAX;
            if(j>=w[i]){
                take=1+dp[i][j-w[i]];
            }
            int not_take=dp[i-1][j];
            dp[i][j]=min(take,not_take);
        }
    }
    if(dp[n-1][amount]==INT_MAX){
        return -1;
    }
    return dp[n-1][amount];
}
// using space optimization 
int using_space_optimization(vector<int>& w,int amount,int n){
    vector<long int> pre(amount+1,0);
    if(amount==0){
        return 0;
    }
    for(int i=1;i<=amount;i++){
        if(i%w[0]==0){
            pre[i]=i/w[0];
        }else{
            pre[i]=INT_MAX;
        }
    }

    for(int i=1;i<n;i++){
        vector<long int>temp(amount+1,0);
        for(int j=1;j<=amount;j++){
            long int take=INT_MAX;
            if(j>=w[i]){
                take=1+temp[j-w[i]];
            }
            long int not_take=pre[j];
            temp[j]=min(take,not_take);
        }
        pre=temp;
    }
    if(pre[amount]==INT_MAX){
        return -1;
    }
    return pre[amount];
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> w(n,0);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int amount;
    cin>>amount;
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    int ans=solve(n-1,w,v,amount,dp);
    int ans2=Bottom_up(w,v,amount,n);
    int ans3=space_optimization(w,v,amount,n);
    int ans4=using_one_array(w,v,amount,n);
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    cout<<ans4<<endl;
    }
}
