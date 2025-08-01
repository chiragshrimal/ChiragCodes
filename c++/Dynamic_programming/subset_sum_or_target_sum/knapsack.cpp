#include<bits/stdc++.h>
using namespace std;

// brute force apporach 
// time complexity is O(2^n)
// space complexity is O(n)

int brute_force(int index,vector<int>& w,vector<int> & v,int max_weight){
    if(index==0){
        if(max_weight==0){
            return 0;
        }else{
            if(max_weight>=w[0]){
                return v[0];
            }
        }
        return INT_MIN;
    }

    int take=INT_MIN;
    if(max_weight>=w[index]){
        take=v[index]+brute_force(index-1,w,v,max_weight-w[index]);
    }
    int not_take=brute_force(index-1,w,v,max_weight);
    return max(take,not_take);
}
// top-down apporach 
// time complexity is o(n*max_weight)
// space complexity is O(n*max_weight)+O(n)
int solve(int index,vector<int>& w,vector<int> & v,int max_weight,vector<vector<int>>& dp){
    if(index<0){
        return 0;
    }
    if(dp[index][max_weight]!=-1){
        return dp[index][max_weight];
    }
    int take=0;
    if(max_weight>=w[index]){
        take=v[index]+solve(index-1,w,v,max_weight-w[index],dp);
    }
    int not_take=solve(index-1,w,v,max_weight,dp);
    return dp[index][max_weight]=max(take,not_take);
}

// bottom up apporach 
// ṭime complexity is O(n*max_weight)
// space complexity is O(n*max_weight)
int Bottom_up(vector<int> & w,vector<int>& v,int max_weight,int n){
    vector<vector<int>> dp(n,vector<int>(max_weight+1,0));

    for(int i=w[0];i<=max_weight;i++){
        dp[0][i]=v[0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=max_weight;j++){
            int take=0;
            if(j>=w[i]){
                take=v[i]+dp[i-1][j-w[i]];
            }
            int not_take=dp[i-1][j];
            dp[i][j]=max(take,not_take);
        }
    }
    return dp[n-1][max_weight];
}

// space optimization 
// time complexity is o(n*max_weight)
// space compelxity is O(max_weight)

int space_optimization(vector<int>& w,vector<int> & v,int max_weight,int n ){
     vector<int> pre(max_weight+1,0);
    
    for(int i=w[0];i<=max_weight;i++){
        pre[i]=v[0];
    }

    for(int i=1;i<n;i++){
        vector<int> temp(max_weight+1,0);
        for(int j=1;j<=max_weight;j++){
            int take=0;
            if(j>=w[i]){
                take=v[i]+pre[j-w[i]];
            }
            int not_take=pre[j];
            temp[j]=max(take,not_take);
        }
        pre=temp;
    }
    return pre[max_weight];
}

// we can do using only one array 
int using_one_array(vector<int>& w,vector<int> & v,int max_weight,int n ){
     vector<int> pre(max_weight+1,0);
    
    for(int i=w[0];i<=max_weight;i++){
        pre[i]=v[0];
    }

    for(int i=1;i<n;i++){
        // vector<int> temp(max_weight+1,0);
        for(int j=max_weight;j>=1;j--){
            int take=0;
            if(j>=w[i]){
                take=v[i]+pre[j-w[i]];
            }
            int not_take=pre[j];
            pre[j]=max(take,not_take);
        }
    }
    return pre[max_weight];
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
    int max_weight;
    cin>>max_weight;
    vector<vector<int>> dp(n,vector<int>(max_weight+1,-1));
    int brute=brute_force(n-1,w,v,max_weight);
    int ans=solve(n-1,w,v,max_weight,dp);
    int ans2=Bottom_up(w,v,max_weight,n);
    int ans3=space_optimization(w,v,max_weight,n);
    int ans4=using_one_array(w,v,max_weight,n);
    if(brute==INT_MIN){
        cout<<"0"<<endl;
    }else{
      cout<<brute<<endl;
    }
    cout<<ans<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
    cout<<ans4<<endl;
    }
}
