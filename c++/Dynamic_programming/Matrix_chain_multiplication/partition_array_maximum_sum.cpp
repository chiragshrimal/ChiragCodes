#include <bits/stdc++.h>
using namespace std;

// brute apporach
// time compllexity is O()
// space complexity is O()

int brute_apporach(vector<int> &arr, int i,int k)
{
    if (i == arr.size())
    {
        return 0;
    }
    int ans = 0;
    int maxi = 0;
    for (int j = i; j <= min((int)arr.size() - 1, i + k - 1); j++)
    {
        maxi = max(maxi, arr[j]);
        int temp = maxi * (j - i + 1) + brute_apporach(arr, j + 1 , k);
        ans = max(ans, temp);
    }
    return ans;
}

// memo_top_Down_apporach
// time complexity is O()
// space complexity is O()

int memo_top_down(vector<int> &arr, int i, int k ,vector<int> &dp)
{
    if (i == arr.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int ans = 0;
    int maxi = 0;
    for (int j = i; j <= min((int)arr.size() - 1, i + k - 1); j++)
    {
        maxi = max(maxi, arr[j]);
        int temp = maxi * (j - i + 1) + memo_top_down(arr, j + 1,k,dp);
        ans = max(ans, temp);
    }
    return dp[i] = ans;
}

// bottom up aporach
// time complexity is O()
// space complexity is O()

int bottom_up_apporach(vector<int> &arr,int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = 0;
        int maxi = 0;
        for (int j = i; j <= min((int)arr.size() - 1, i + k - 1); j++)
        {
            maxi = max(maxi, arr[j]);
            int temp = maxi * (j - i + 1) + dp[j+1];
            ans = max(ans, temp);
        }
        dp[i] = ans;
    }
    return dp[0];
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"using brute apporoach "<<endl;
    int brute=brute_apporach(arr,0,k);
    cout<<brute<<endl;

    cout<<"using memo_top_down apporach "<<endl;
    vector<int> dp(n,-1);
    int memo=memo_top_down(arr,0,k,dp);
    cout<<memo<<endl;

    cout<<"using bottom up apporach "<<endl;
    int bottom=bottom_up_apporach(arr,k);
    cout<<bottom<<endl;
}