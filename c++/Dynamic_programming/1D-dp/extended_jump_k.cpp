#include <bits/stdc++.h>
using namespace std;

// brute apporach
// time complexity is O(2^n*k)
// space complexity is O(n)

int brute_apporach(int n, vector<int> &arr, int k)
{
    // index=0 par khade hone ki cost hai
    if (n == 0)
    {
        return 0;
    }
    // index=1 par khade hone ki cost hai
    if (n == 1)
    {
        return abs(arr[1] - arr[0]);
    }
    int ans = INT_MAX;
    for (int i = n - 1; i >= 0 && i >= n - k; i--)
    {
        ans = min(ans, abs(arr[n] - arr[i]) + brute_apporach(i, arr,k));
    }
    return ans;
}

// optimal apporach
// apply top down with dp
// time complexity is o(2*n*k)
// space complexity is o(n)

int top_down_optimal_apporach(int n, vector<int> &arr, vector<int> &dp, int k)
{
    // index=0 par khade hone ki cost hai
    if (n == 0)
    {
        return 0;
    }
    // index=1 par khade hone ki cost hai
    if (n == 1)
    {
        return abs(arr[1] - arr[0]);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = INT_MAX;
    for (int i = n - 1; i >= 0 && i >= n - k; i--)
    {
        ans = min(ans, abs(arr[n] - arr[i]) + top_down_optimal_apporach(i, arr,dp,k));
    }
    return dp[n] = ans;
}

// apply bottom apporach
// time complexity is o(n*k)
// space complexity is O(n)

int bottom_apporach(int n, vector<int> &arr,int k)
{
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for (int i = 2; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = i - 1; j >= 0 && j >= i - k; j--)
        {
            ans = min(ans, abs(arr[i] - arr[j]) + dp[j]);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "using brute apporach " << endl;
    int brute = brute_apporach(n - 1, arr,k);
    cout << brute << endl;

    vector<int> dp(n, -1);
    cout << "using dp " << endl;
    int optimal = top_down_optimal_apporach(n - 1, arr, dp,k);
    cout << optimal << endl;

    cout << "using bottom apporach" << endl;
    int bottom = bottom_apporach(n - 1, arr,k);
    cout << bottom << endl;

}