#include <bits/stdc++.h>
using namespace std;

// top down apporach
// time complexity is O()
// space complexity is O()

int brute_apporch(vector<int>&arr, int index, int pre_ind)
{
    if (index == arr.size())
    {
        return 0;
    }
    // take
    int take = 0;
    if (pre_ind == -1 || arr[index] > arr[pre_ind])
    {
        take = 1+brute_apporch(arr, index + 1, index);
    }
    // not_take
    int not_take = brute_apporch(arr, index + 1, pre_ind);
    return max(take, not_take);
}

// memorize_top_down apporach
// time complexity is O()
// space complexity is o()

// because pre_ind can also be nagative so you have shift one position ahead
int memorize_top_down(vector<int> &arr, int index, int pre_ind, vector<vector<int>> &dp)
{
    if (index == arr.size())
    {
        return 0;
    }
    if (dp[index][pre_ind + 1] != -1)
    {
        return dp[index][pre_ind];
    }
    // take
    int take = 0;
    if (pre_ind == -1 || arr[index] > arr[pre_ind])
    {
        take = 1 + memorize_top_down(arr, index + 1, index ,dp);
    }
    // not_take
    int not_take = memorize_top_down(arr, index + 1, pre_ind ,dp);
    return dp[index][pre_ind + 1] = max(take, not_take);
}

// bottom_up apporach
// time complexity is o()
// space complexity is o()

int bottom_up_apporach(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // base case 
    for(int i=0;i<=n;i++){
        dp[n][i]=0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int pre_ind = i - 1; pre_ind >= -1; pre_ind--)
        {
            // take
            int take = 0;
            if (pre_ind == -1 || arr[i] > arr[pre_ind])
            {
                // because of shift pre_ind m i+1 hi hoga na 
                take = 1 + dp[i+1][i+1];
            }
            // not_take
            int dont_take =dp[i+1][pre_ind+1];
            dp[i][pre_ind+1]=max(take,dont_take);
        }
    }
    return dp[0][0];
}

// do space optimization 
// time complexity is O()
// space complexity is O()

int space_optimization(vector<int>&arr){
    int n = arr.size();
    vector<int> next(n+1,0);
    vector<int> curr(n+1,0);
    // base case already written
    for (int i = n - 1; i >= 0; i--)
    {
        for (int pre_ind = i - 1; pre_ind >= -1; pre_ind--)
        {
            // take
            int take = 0;
            if (pre_ind == -1 || arr[i] > arr[pre_ind])
            {
                take = 1+ next[i+1];
            }
            // not_take
            int dont_take =next[pre_ind+1];
            curr[pre_ind+1]=max(take,dont_take);
        }
        next=curr;
    }
    return next[0];

}


// most optimal apporach for LIS 
// solve most of the question using this apporach 
// time complexity is O()
// space complexity is O()

int most_optimal_tabulation(vector<int>&arr){
    int n=arr.size();
    vector<int> dp(n,1);
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                maxi=max(maxi,dp[i]);
            }
        }
    }
    return maxi;
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"using brute_apporach "<<endl;
    int brute=brute_apporch(arr,0,-1);
    cout<<brute<<endl;

    cout<<"using top_down "<<endl;
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    int memo=memorize_top_down(arr,0,-1,dp);
    cout<<memo<<endl;

    cout<<"using bottom apporach"<<endl;
    int bottom=bottom_up_apporach(arr);
    cout<<bottom<<endl;

    cout<<"using space optimization "<<endl;
    int space=space_optimization(arr);
    cout<<space<<endl;

    cout<<"using most optimal tabulation "<<endl;
    int most_optimal=most_optimal_tabulation(arr);
    cout<<most_optimal<<endl;

}